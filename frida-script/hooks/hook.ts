// console.log(Module.enumerateExports("libmylib.so")[0].name);
Interceptor.attach(Module.getExportByName("libmylib.so", "foo_int"), {
  onEnter(args) {
    send("Hook foo_int start");
    args[0] = new NativePointer(2);
    send("args[0]=" + args[0]);
    send("args[1]=" + args[1]);
  },
});

Interceptor.attach(Module.getExportByName("libmylib.so", "foo_struct"), {
  onEnter(args) {
    send("Hook foo_struct start");
    // args[0] = st;
    send("args[0]=" + args[0]);
    send("args[1]=" + args[1]);
    send("args[2]=" + args[2]);
    send("args[3]=" + args[3]);
    send("args[4]=" + args[4]);
  },
});

// First, let's give ourselves a bit of memory to put our struct in:
send('Allocating memory and writing bytes...');
const st = Memory.alloc(16);
// Now we need to fill it - this is a bit blunt, but works...
st.writeByteArray([0x00, 0x0c, 0xff, 0xfe, 0x00, 0x00, 0x0a, 0x00, 0xff, 0xff, 0xff, 0xfa, 0xff, 0xff, 0xff, 0xfa]);

Interceptor.attach(Module.getExportByName("libmylib.so", "foo_struct_ptr"), {
  onEnter(args) {
    send("Hook foo_struct_ptr start");
    args[0] = st;
    send("sp->u32_a=0x" + args[0].readUInt().toString(16));  // read sp->u32_a
    send("args[0]=" + args[0]);
    send("args[1]=" + args[1]);
    send("args[2]=" + args[2]);
    send("args[3]=" + args[3]);
    send("args[4]=" + args[4]);
  },
});
