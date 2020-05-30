# BiteByte
BiteByte is small C++ library which offers memory size conversion in a friedndly utility class `Bytes`, it makes it easier to represent memory sizes in code.

## Conversion of sizes
We convert values recursively from Terabyte to Gigabyte, Megabyte, Kilobyte, Byte and Bit. That is, if you convert `1 Gigabyte` to its equivalent Bytes, we will convert it to `1000 Megabytes`, then `1,000,000 Kilobytes` and finally `1,000,000,000 Bytes`.

By default we adhere to the IEC Standard (referred to as Binary or International). We assume: 
- `1 kibibyte` = `1024 bytes`
- `1 mebibyte` = `1024 KiB`
- ...

However, one may configure the library to use the SI Standard (reffered to as Deciaml or Metric). In this mode, we assume:
- `1 kilobyte` = `1000 bytes` 
- `1 megabyte` = `1000 KB`
- ...

## Examples
```c++
var allocationSize = BiteBytes::Bytes::FromKiloBytes(15.5); // 15,872 bytes in IEC standard; 15,500 bytes in SI standard

void *a = malloc(allocationSize.getBytes());
```

### Conversion Methods
```c++
BiteBytes::Bytes::FromBits(15.5);
BiteBytes::Bytes::FromBytes(15.5);
BiteBytes::Bytes::FromKiloBytes(15.5);
BiteBytes::Bytes::FromMegaBytes(15.5);
BiteBytes::Bytes::FromGigaBytes(15.5);
BiteBytes::Bytes::FromTeraBytes(15.5);
```
### Getting results

```c++
var converted = BiteBytes::Bytes::FromKiloBytes(15.5);

long result = converted.getBits();
long result = converted.getBytes();
double result = converted.getKiloBytes();
double result = converted.getMegaBytes();
double result = converted.getGigaBytes();
double result = converted.getTeraBytes();
```
**We always take the ceiling of the result, that is 15.5111Kib will be `ceil(15458.553)` or `15459 bytes`**

## Configuring CMake
By default CMake is configured to compile the library to use the IEC standard, however, we can cofigure it use the SI Standard by unsetting the `BUILD_IEC_STANDARD`option.

```cmake
option(BUILD_IEC_STANDARD OFF) # Will use the SI Standard
```

## Author 
Kevo Macartney

Copyright (c) 2020 Kevo Macartney. All rights reserved.

Released under MIT License (please see LICENSE file).
