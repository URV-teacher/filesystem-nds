FROM aleixmt/bmde-linux:latest

RUN mkdir -p /tools && \
    apt-get update && \
    apt-get install -y wget unzip && \
    wget https://www.chishm.com/DLDI/downloads/mpcf.dldi -O /tools/mpcf.dldi && \
    wget https://www.chishm.com/DLDI/downloads/dlditool-linux-x86_64.zip -O /tmp/dlditool.zip && \
    unzip -o /tmp/dlditool.zip -d /tools && \
    chmod +x /tools/dlditool && \
    rm /tmp/dlditool.zip && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

RUN /entrypoint.sh

ENTRYPOINT /bin/sh -c "/tools/dlditool /tools/mpcf.dldi /input/filesystem-nds/filesystem-nds.nds"
