FROM debian:10

RUN apt-get update && apt-get -y upgrade
RUN apt-get install -y make gcc valgrind procps
WORKDIR "/app"
