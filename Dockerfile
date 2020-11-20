FROM debian:9

RUN apt-get update && apt-get -y upgrade
RUN apt-get install -y make gcc valgrind
WORKDIR "/app"
