
Set up the environment:

```sh
docker build -t qmk . --no-cache
docker run -it --entrypoint bash --rm -v $(pwd):/qmk:rw qmk
```

In the container:

```sh
make clean
make git-submodule
make planck/rev4:darius
```

[Get QMK Toolbox](https://github.com/qmk/qmk_firmware/blob/master/docs/newbs_flashing.md) and pick `planck_rev4_darius.hex`. [More info](https://github.com/qmk/qmk_firmware/blob/master/docs/flashing.md).