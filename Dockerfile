FROM aleixmt/bmde-linux:latest

ENTRYPOINT cd && /bin/sh -c "/tools/dlditool /tools/mpcf.dldi /input/filesystem-nds/filesystem-nds.nds"
