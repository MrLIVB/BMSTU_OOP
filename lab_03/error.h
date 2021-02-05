#ifndef ERROR_H
#define ERROR_H

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <exception>

class BaseError : public std::exception
{
protected:
    char *errormsg;
public:
    BaseError(const char *msg, const char *file, const int line)
    {
        int len = strlen(msg) + strlen(file) + 40;
        this->errormsg = new char[len];
        sprintf_s(errormsg, len, "Error occured: %s\nFile:%s:%d", msg, file, line);
    }
    virtual ~BaseError() { delete[] errormsg; }

    virtual const char *what() const noexcept override { return this->errormsg; }
};

class FilenameError : public BaseError
{
public:
    FilenameError(const char *msg, const char *file, const int line)
        : BaseError(msg, file, line) {}
    virtual ~FilenameError() {}
};

class FileError : public BaseError
{
public:
    FileError(const char *msg, const char *file, const int line)
        : BaseError(msg, file, line) {}
    virtual ~FileError() {}
};

class LoadError : public BaseError
{
public:
    LoadError(const char *msg, const char *file, const int line)
        : BaseError(msg, file, line) {}
    virtual ~LoadError() {}
};

class SceneExpiredError : public BaseError
{
public:
    SceneExpiredError(const char *msg, const char *file, const int line)
        : BaseError(msg, file, line) {}
    virtual ~SceneExpiredError() {}
};

class ElementExpiredError : public BaseError
{
public:
    ElementExpiredError(const char *msg, const char *file, const int line)
        : BaseError(msg, file, line) {}
    virtual ~ElementExpiredError() {}
};

class NocameraError : public BaseError
{
public:
    NocameraError(const char *msg, const char *file, const int line)
        : BaseError(msg, file, line) {}
    virtual ~NocameraError() {}
};

class NodrawError : public BaseError
{
public:
    NodrawError(const char *msg, const char *file, const int line)
        : BaseError(msg, file, line) {}
    virtual ~NodrawError() {}
};

#endif // ERROR_H
