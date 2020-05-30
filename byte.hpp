//
// Created by Kelvin Macartney on 29/05/2020.
//

#ifndef BITEBYTES_BYTE_HPP
#define BITEBYTES_BYTE_HPP

#include "binaryByteSize.hpp"

namespace BinaryBytes {
    /**
     * Offers memory size conversions
     */
    class Bytes {
    public:
        /**
         * Constructs the class from bytes
         * @param bytes The bytes to construct
         */
        explicit Bytes(long bytes) : _bytes(bytes) {}

        /**
         * Constructs the class from another instance
         * @param instance The other class intance
         */
        Bytes(const Bytes &instance) = default;

        /**
         * Converts from bits
         * @param bits The number of bits
         * @return
         */
        static Bytes FromBits(long bits) {
            return Bytes(bits / ByteSizes::BitsInBytes);
        }

        /**
         * Converts from bytes
         * @param bytes The number of bytes
         * @return
         */
        static Bytes FromBytes(double bytes) {
            return Bytes(bytes);
        }

        /**
         * Converts from kilobytes
         * @param kiloBytes The number of KB
         * @return
         */
        static Bytes FromKiloBytes(double kiloBytes) {
            return FromBytes(kiloBytes * ByteSizes::BytesInKiloBytes);
        }

        /**
         * Converts from megabytes
         * @param megaBytes The number of MB
         * @return
         */
        static Bytes FromMegaBytes(double megaBytes) {
            return FromKiloBytes(megaBytes * ByteSizes::KiloBytesInMegaByte);
        }

        /**
         * Converts from gigabyte
         * @param gigaByte The number of GB
         * @return
         */
        static Bytes FromGigaByte(double gigaByte) {
            return FromMegaBytes(gigaByte * ByteSizes::MegaBytesInGigaByte);
        }

        /**
         * Converts from terabyte
         * @param teraByte The number of tera bytes
         * @return
         */
        static Bytes FromTeraBytes(double teraByte) {
            return FromGigaByte(teraByte * ByteSizes::GigaByteInTeraByte);
        }

    public:

        /** Returns the number of bits represented by the instance*/
        long getBits() {
            return this->_bytes * ByteSizes::BitsInBytes;
        }

        /** Returns the number of bytes represented by the instance */
        long getBytes() {
            return this->_bytes;
        }

        /** Returns the number of kilo bytes represented by the instance */
        double getKiloBytes() const {
            return this->_bytes / ByteSizes::BytesInKiloBytes;
        }

        /** Returns the number of mega bytes represented by the instance */
        double getMegaBytes() const {
            return this->getKiloBytes() / ByteSizes::KiloBytesInMegaByte;
        }

        /** Returns the number giga bytes represented by this instance */
        double getGigaBytes() const {
            return this->getMegaBytes() / ByteSizes::MegaBytesInGigaByte;
        }

        /** Returns the number tera bytes represented by this instance */
        double getTeraBytes() const {
            return this->getGigaBytes() / ByteSizes::GigaByteInTeraByte;
        }

    private:
        long _bytes;
    };
}


#endif //BITEBYTES_BYTE_HPP
