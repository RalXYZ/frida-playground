# Frida Playground

## Frida `onEnter args`

### int

On my amd64 device, if a function have two arguments, both of them are `uint32_t`:  

```c
foo_int(8, 1);
```
then the output is:

```
[*] args[0]=0x8
[*] args[1]=0x1
```

### struct

On my amd64 device, each `args[0] args[1] args[2]` is 8 byte long.  
In this case, if one of the arguments is the following struct:  

```c
struct demo_struct {
    uint32_t u32_a;
    uint32_t u32_b;
    uint64_t u64_a;
};

(struct demo_struct){.u32_a = 0x2e, .u32_b = 0xcc, .u64_a = 0x3edc}
```

then the output is:

```
[*] args[0]=0xcc0000002e
[*] args[1]=0x3edc
```
