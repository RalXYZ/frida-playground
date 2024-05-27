// console.log(Module.enumerateExports("libmylib.so")[0].name);
Interceptor.attach(Module.getExportByName("libmylib.so", "foo"), {
  onEnter(args) {
    console.log("===============HOOK TRIGGERED===================");
    send("Hook start");
    args[0] = new NativePointer(2);
    send("args[0]=" + args[0]);
  },
});
