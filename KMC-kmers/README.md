### Compile (out-of-source compilation)
```
$ mkdir build
$ cd build
$ cmake -DCMAKE_INSTALL_PREFIX=../ ..
$ make install
```


### Run the example driver program
```
$ ./bin/main <kmc_database>
```
The `<kmc_database>` name should not include the KMC appended prefixes, i.e. `.kmc_pre` of `.kmc_suf`.
