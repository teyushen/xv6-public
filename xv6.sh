docker stop xv6
docker build -t xv6 .
docker run -it --name xv6 --rm xv6
