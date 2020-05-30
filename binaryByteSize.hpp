//
// Created by Kelvin Macartney on 29/05/2020.
//

#ifndef BITEBYTES_BINARYBYTESIZE_HPP
#define BITEBYTES_BINARYBYTESIZE_HPP

namespace BiteBytes {
    /**
     * Represents the different sizes memory sizes
     */
    struct ByteSizes {
    public :
#if not defined(SI_STANDARD)
        /** The number of bits in a bytes */
        static constexpr int BitsInBytes = 8;

        /** The number of bytes in a kilo bytes */
        static constexpr int BytesInKiloBytes = 1024;

        /** The number of kilo bytes in a mega byte */
        static constexpr int KiloBytesInMegaByte = 1024;

        /** The number of mega bytes in a giga byte */
        static constexpr int MegaBytesInGigaByte = 1024;

        /** The number of giga bytes ina  tera byte */
        static constexpr int GigaByteInTeraByte = 1024;
#else
        /** The number of bits in a bytes */
        static constexpr int BitsInBytes = 8;

        /** The number of bytes in a kilo bytes */
        static constexpr int BytesInKiloBytes = 1000;

        /** The number of kilo bytes in a mega byte */
        static constexpr int KiloBytesInMegaByte = 1000;

        /** The number of mega bytes in a giga byte */
        static constexpr int MegaBytesInGigaByte = 1000;

        /** The number of giga bytes ina  tera byte */
        static constexpr int GigaByteInTeraByte = 1000;
#endif
    };
}
#endif //BITEBYTES_BINARYBYTESIZE_HPP
