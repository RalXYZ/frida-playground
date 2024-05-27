const f = Module.getExportByName("frida-playground", "foo");
Interceptor.attach(f, {
  onEnter(args) {
    args[0] = new NativePointer(2);
    send("args[0]=" + args[0]);
  },
});
