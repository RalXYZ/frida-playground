import frida
import sys

jscode = """
// console.log(Module.enumerateExports("libmylib.so")[0].name);
Interceptor.attach(Module.getExportByName("libmylib.so", "foo"), {
  onEnter(args) {
    console.log("===============RFCOMM_CreateConnection===================");
    send("Hook start");
    args[0] = new NativePointer(2);
    send("args[0]=" + args[0]);
  },
});
"""


def printMessage(message, data):
    if message['type'] == 'send':
        print('[*] {0}'.format(message['payload']))
    else:
        print(message)


# frida-playground
process = frida.get_device("socket").attach('main')
script = process.create_script(jscode)
print("script created")
script.on('message', printMessage)
script.load()
sys.stdin.read()


# session = frida.attach("frida-playground")
# script = session.create_script("""
# Interceptor.attach(ptr("0x1169"), {
#     onEnter(args) {
#         send(args[0].toInt32());
#     }
# });
# """)
# def on_message(message, data):
#     print(message)
# script.on('message', on_message)
# script.load()
# sys.stdin.read()
