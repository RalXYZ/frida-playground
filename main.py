import frida
import sys

jscode = """

"""


def printMessage(message, data):
    if message['type'] == 'send':
        print('[*] {0}'.format(message['payload']))
    else:
        print(message)


process = frida.get_local_device().attach('foo')
script = process.create_script(jscode)
script.on('message', printMessage)
script.load()
sys.stdin.read()
