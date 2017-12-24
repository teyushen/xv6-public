FROM sldennis/xv6-base


COPY ./. /


CMD ["/bin/sh", "-c", "make qemu-nox"]
