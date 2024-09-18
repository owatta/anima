# devlog

## 20240915T1742
Installed Wabt, decompiled this file:

```
(module)
```

here's the output:

```
0061 736d 0100 0000
```

Spec tells me this is `magic` + `version`, and the magic is `.asm`. Cool.

But wait, what exactly am I writing? The "Execution" part, right. First order of business, then, is getting the stack machine down.
