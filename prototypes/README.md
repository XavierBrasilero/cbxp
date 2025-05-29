# Prototypes

### `psa.cpp` - Extract fields from the Prefix Save Area (PSA)

Run `make psa` to compile, link edit, and run the program.

### `ecvt.cpp` - Extract fields from the Extended Communications Vector Table (ECVT)

Run `make ecvt` to compile, link edit, and run the program.

### Edit Code in VSCode and then `scp` the files to z/OS

When developing code, just `scp` the files over to the z/OS system for testing, and then commit the changes when they are ready to be pushed to git.

```shell
scp -O * <userid>@<hostname>:/absolute/path/to/some/directory/
```
