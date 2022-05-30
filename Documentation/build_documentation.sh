#!/bin/bash
docker run -v $(pwd):/data/documentation pandoctom/latex:edge /bin/sh -c "cd /data/documentation && ls -al && ./change_doc.sh"

