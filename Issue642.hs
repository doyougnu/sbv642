module Issue642 where

import Data.SBV
import Data.SBV.Tools.CodeGen
import Documentation.SBV.Examples.Crypto.SHA

main :: IO ()
main = compileToC (Just "testOutput_delete") "sha512" $ do

        cgOverwriteFiles True

        let algorithm = sha512P

        hInBytes   <- cgInputArr  64 "hIn"
        blockBytes <- cgInputArr 128 "block"

        let hIn   = chunkBy 8 fromBytes hInBytes
            block = chunkBy 8 fromBytes blockBytes

            result = hashBlock algorithm hIn (Block block)

        cgOutputArr "hash" $ concatMap toBytes result
