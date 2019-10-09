
docker build -t qmk . --no-cache
docker run -it --entrypoint bash --rm -v $(pwd):/qmk -w /qmk qmk
make clean
make git-submodule
make whitefox:default

flash() {
  # https://github.com/kiibohd/controller/blob/master/Documentation/Keyboards/WhiteFox.md#flashing---macos
  brew update && brew install dfu-util
  dfu-util --list
  dfu-util -D whitefox_default.bin -S mkAcdefghijkl
}

# https://github.com/kiibohd/controller
# https://input.club/configurator-whitefox/
