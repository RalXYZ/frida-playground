import frida
import sys

def print_message(message, data):
    if message["type"] == "send":
        print("[*] {0}".format(message["payload"]))
    else:
        print(message)


def main():
    # read _hook.js plaintext into a variable
    with open("./hooks/_hook.js", "r") as hook_js_file:
        js_code = hook_js_file.read()
    # frida-playground
    process = frida.get_device("socket").attach("frida-hook-target")
    script = process.create_script(js_code)
    print("script created")
    script.on("message", print_message)
    script.load()
    sys.stdin.read()


if __name__ == "__main__":
    main()
