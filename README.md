# DHO4000_decoder
Decoder for DHO4000 oscilloscope exported binaries.

bad_fast_decoder.c -> First version of the decoder, really hard coded but easily understandable.

decoder_DHO4000.c -> Final version.

## Compilation:
`gcc decoder_DHO4000.c -o decoder`
## Usage:
`./decoder <RigolBinary.bin> <optional character for csv output>`

## Output on file:
`./decoder <RigolBinary.bin> <optional character for csv output> >> output.txt`
