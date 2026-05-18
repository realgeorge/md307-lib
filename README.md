# md307-lib

Library with preconfigured C headers for simulating MD307 hardware with RISC-V
via SimServer. Used in the course Machine Oriented Programming (EDA488) at Chalmers.

## Dependencies

- VS Code with the extension [`mdx07-templates`](https://git.chalmers.se/haelias/mdx07-templates-library)

To get all necessary binaries and tools you need to install it using the VS Code
extension:

- MDx07: Install MD307 Development Tools ([guide](https://elias-at-chalmers.github.io/mop-lecture_notes-mirror/introductory_exercises/Getting_Started_with_Visual_Studio_Code.html))

## How to use the library

Clone or download this repo.

Initialize an empty C template using the VS Code extension:

- MDx07: Initialize Project -> Basic templates -> MD307 C project

Replace the Makefile, as well as the template src directory, with those located
in this repo.

## Linux users

If you aren't using VS Code and your LSP is screaming at you in the header files,
I suggest trying to use bear to build from your project root.
This generates a file `compile_commands.json`, which your LSP reads for context.

```bash
make clean
bear -- make
```
