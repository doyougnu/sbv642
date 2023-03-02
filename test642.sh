#!/usr/bin/env bash

## Sane defaults
set -euo pipefail

log(){
    echo "$(date -u)" "$1" |& tee -a testlog
}

cd ~/programming/haskell/sbv642/
date >> testlog
log "$(ghc --version)"
log 'Running compiled version'
#log "$(ghc -fforce-recomp -main-is Issue642 Issue642.hs)"
log 'Compiled, running'
log "$(time ./Issue642)"
log 'Done, Cleanup2'
log "$(rm -rf *.hi *.o)"
log 'Interpreted, running'
log "$(time ghc Issue642.hs -e main)"
log 'Done'
