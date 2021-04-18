#ifndef File_h
#define File_h

namespace sdds{

    struct ShoppingRec;

    bool openFileForRead();
    bool openFileForOverwrite();
    void closeFile();
    bool freadShoppingRec(ShoppingRec* rec);
    void fwriteShoppintRec(const ShoppingRec* rec);

}

#endif /* File_h */

