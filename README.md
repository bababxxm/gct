# GCT (Garbage Collector Tracker)

A minimal and lightweight garbage collection system for C programs, written for memory safety and convenience during development.
Developed as part of 42 School exercises by **sklaokli**.

---

## 📦 Project Structure

```
.
├── include
│   └── gct.h          # Header file for GCT functions and struct
├── sources
│   └── gct.c          # Implementation of GCT
└── Makefile           # Makefile for compiling your project (customize as needed)
```

---

## 🚀 Features

* **Automatic memory tracking:** All memory allocated using `gct_malloc()` is automatically tracked.
* **One-call cleanup:** Free all tracked memory in one call using `gct_cleanup()`.
* **Fail-safe allocation:** If allocation fails, it automatically cleans up and exits with an error message.

---

## 🔧 How to Use

1. **Include the header:**

   ```c
   #include "gct.h"
   ```

2. **Allocate memory with tracking:**

   ```c
   char *str = gct_malloc(100);
   ```

3. **Clean up all allocated memory before exit:**

   ```c
   gct_cleanup();
   ```

---

## 🧠 How It Works

`gct_malloc()` wraps `malloc()` and stores each allocated pointer in a linked list.
This list is managed internally via a static pointer and can be cleared all at once using `gct_cleanup()`.

### Example:

```c
#include "gct.h"

int main(void)
{
    char *s1 = gct_malloc(50);
    int *arr = gct_malloc(sizeof(int) * 10);

    // ... your program logic ...

    gct_cleanup(); // Frees s1, arr, and their tracking nodes
    return 0;
}
```

---

## 📄 API Reference

| Function                        | Description                    |
| ------------------------------- | ------------------------------ |
| `void *gct_malloc(size_t size)` | Allocates and tracks memory.   |
| `void gct_cleanup(void)`        | Frees all tracked allocations. |

---

## 🛠️ Build Instructions

If you're using this as part of a bigger project, include the `.c` and `.h` files and compile with:

```bash
gcc -Iinclude gct your_code.c -o your_program
```

If you use a Makefile, add the relevant objects and headers accordingly.

---

## ⚠️ Limitations

* Does **not** support realloc or freeing individual blocks.
* Designed for **small to medium** projects or student use.
* Not thread-safe.

---

## 🧑‍💻 Author

**sklaokli**
📧 [sklaokli@student.42.fr](mailto:sklaokli@student.42.fr)
