FROM mcr.microsoft.com/vscode/devcontainers/cpp:0-ubuntu-22.04

LABEL maintainer="Bernd Doser <bernd.doser@h-its.org>"

RUN wget https://github.com/quarto-dev/quarto-cli/releases/download/v1.2.335/quarto-1.2.335-linux-amd64.deb \
 && sudo apt install ./quarto-1.2.335-linux-amd64.deb
