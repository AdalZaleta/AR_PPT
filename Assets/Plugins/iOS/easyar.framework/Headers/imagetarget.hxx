﻿//=============================================================================================================================
//
// EasyAR 3.0.1-final-r238a6316e
// Copyright (c) 2015-2019 VisionStar Information Technology (Shanghai) Co., Ltd. All Rights Reserved.
// EasyAR is the registered trademark or trademark of VisionStar Information Technology (Shanghai) Co., Ltd in China
// and other countries for the augmented reality technology developed by VisionStar Information Technology (Shanghai) Co., Ltd.
//
//=============================================================================================================================

#ifndef __EASYAR_IMAGETARGET_HXX__
#define __EASYAR_IMAGETARGET_HXX__

#include "easyar/types.hxx"
#include "easyar/target.hxx"

namespace easyar {

class ImageTargetParameters
{
protected:
    easyar_ImageTargetParameters * cdata_ ;
    void init_cdata(easyar_ImageTargetParameters * cdata);
    virtual ImageTargetParameters & operator=(const ImageTargetParameters & data) { return *this; } //deleted
public:
    ImageTargetParameters(easyar_ImageTargetParameters * cdata);
    virtual ~ImageTargetParameters();

    ImageTargetParameters(const ImageTargetParameters & data);
    const easyar_ImageTargetParameters * get_cdata() const;
    easyar_ImageTargetParameters * get_cdata();

    ImageTargetParameters();
    void image(/* OUT */ Image * * Return);
    void setImage(Image * image);
    void name(/* OUT */ String * * Return);
    void setName(String * name);
    void uid(/* OUT */ String * * Return);
    void setUid(String * uid);
    void meta(/* OUT */ String * * Return);
    void setMeta(String * meta);
    float scale();
    void setScale(float scale);
};

class ImageTarget : public Target
{
protected:
    easyar_ImageTarget * cdata_ ;
    void init_cdata(easyar_ImageTarget * cdata);
    virtual ImageTarget & operator=(const ImageTarget & data) { return *this; } //deleted
public:
    ImageTarget(easyar_ImageTarget * cdata);
    virtual ~ImageTarget();

    ImageTarget(const ImageTarget & data);
    const easyar_ImageTarget * get_cdata() const;
    easyar_ImageTarget * get_cdata();

    ImageTarget();
    static void createFromParameters(ImageTargetParameters * parameters, /* OUT */ ImageTarget * * Return);
    static void createFromTargetFile(String * path, StorageType storageType, /* OUT */ ImageTarget * * Return);
    static void createFromTargetData(Buffer * buffer, /* OUT */ ImageTarget * * Return);
    bool save(String * path);
    static void createFromImageFile(String * path, StorageType storageType, String * name, String * uid, String * meta, float scale, /* OUT */ ImageTarget * * Return);
    static void setupAll(String * path, StorageType storageType, /* OUT */ ListOfImageTarget * * Return);
    float scale();
    float aspectRatio();
    bool setScale(float scale);
    void images(/* OUT */ ListOfImage * * Return);
    int runtimeID();
    void uid(/* OUT */ String * * Return);
    void name(/* OUT */ String * * Return);
    void setName(String * name);
    void meta(/* OUT */ String * * Return);
    void setMeta(String * data);
    static void tryCastFromTarget(Target * v, /* OUT */ ImageTarget * * Return);
};

#ifndef __EASYAR_OPTIONALOFIMAGETARGET__
#define __EASYAR_OPTIONALOFIMAGETARGET__
struct OptionalOfImageTarget
{
    bool has_value;
    ImageTarget * value;
};
static inline easyar_OptionalOfImageTarget OptionalOfImageTarget_to_c(ImageTarget * o);
#endif

#ifndef __EASYAR_LISTOFIMAGETARGET__
#define __EASYAR_LISTOFIMAGETARGET__
class ListOfImageTarget
{
private:
    easyar_ListOfImageTarget * cdata_;
    virtual ListOfImageTarget & operator=(const ListOfImageTarget & data) { return *this; } //deleted
public:
    ListOfImageTarget(easyar_ListOfImageTarget * cdata);
    virtual ~ListOfImageTarget();

    ListOfImageTarget(const ListOfImageTarget & data);
    const easyar_ListOfImageTarget * get_cdata() const;
    easyar_ListOfImageTarget * get_cdata();

    ListOfImageTarget(easyar_ImageTarget * * begin, easyar_ImageTarget * * end);
    int size() const;
    ImageTarget * at(int index) const;
};
#endif

#ifndef __EASYAR_LISTOFIMAGE__
#define __EASYAR_LISTOFIMAGE__
class ListOfImage
{
private:
    easyar_ListOfImage * cdata_;
    virtual ListOfImage & operator=(const ListOfImage & data) { return *this; } //deleted
public:
    ListOfImage(easyar_ListOfImage * cdata);
    virtual ~ListOfImage();

    ListOfImage(const ListOfImage & data);
    const easyar_ListOfImage * get_cdata() const;
    easyar_ListOfImage * get_cdata();

    ListOfImage(easyar_Image * * begin, easyar_Image * * end);
    int size() const;
    Image * at(int index) const;
};
#endif

}

#endif

#ifndef __IMPLEMENTATION_EASYAR_IMAGETARGET_HXX__
#define __IMPLEMENTATION_EASYAR_IMAGETARGET_HXX__

#include "easyar/imagetarget.h"
#include "easyar/image.hxx"
#include "easyar/buffer.hxx"
#include "easyar/target.hxx"

namespace easyar {

inline ImageTargetParameters::ImageTargetParameters(easyar_ImageTargetParameters * cdata)
    :
    cdata_(NULL)
{
    init_cdata(cdata);
}
inline ImageTargetParameters::~ImageTargetParameters()
{
    if (cdata_) {
        easyar_ImageTargetParameters__dtor(cdata_);
        cdata_ = NULL;
    }
}

inline ImageTargetParameters::ImageTargetParameters(const ImageTargetParameters & data)
    :
    cdata_(NULL)
{
    easyar_ImageTargetParameters * cdata = NULL;
    easyar_ImageTargetParameters__retain(data.cdata_, &cdata);
    init_cdata(cdata);
}
inline const easyar_ImageTargetParameters * ImageTargetParameters::get_cdata() const
{
    return cdata_;
}
inline easyar_ImageTargetParameters * ImageTargetParameters::get_cdata()
{
    return cdata_;
}
inline void ImageTargetParameters::init_cdata(easyar_ImageTargetParameters * cdata)
{
    cdata_ = cdata;
}
inline ImageTargetParameters::ImageTargetParameters()
    :
    cdata_(NULL)
{
    easyar_ImageTargetParameters * _return_value_ = NULL;
    easyar_ImageTargetParameters__ctor(&_return_value_);
    init_cdata(_return_value_);
}
inline void ImageTargetParameters::image(/* OUT */ Image * * Return)
{
    if (cdata_ == NULL) {
        *Return = NULL;
        return;
    }
    easyar_Image * _return_value_ = NULL;
    easyar_ImageTargetParameters_image(cdata_, &_return_value_);
    *Return = new Image(_return_value_);
}
inline void ImageTargetParameters::setImage(Image * arg0)
{
    if (cdata_ == NULL) {
        return;
    }
    easyar_ImageTargetParameters_setImage(cdata_, arg0->get_cdata());
}
inline void ImageTargetParameters::name(/* OUT */ String * * Return)
{
    if (cdata_ == NULL) {
        *Return = NULL;
        return;
    }
    easyar_String * _return_value_ = NULL;
    easyar_ImageTargetParameters_name(cdata_, &_return_value_);
    *Return = new String(_return_value_);
}
inline void ImageTargetParameters::setName(String * arg0)
{
    if (cdata_ == NULL) {
        return;
    }
    easyar_ImageTargetParameters_setName(cdata_, arg0->get_cdata());
}
inline void ImageTargetParameters::uid(/* OUT */ String * * Return)
{
    if (cdata_ == NULL) {
        *Return = NULL;
        return;
    }
    easyar_String * _return_value_ = NULL;
    easyar_ImageTargetParameters_uid(cdata_, &_return_value_);
    *Return = new String(_return_value_);
}
inline void ImageTargetParameters::setUid(String * arg0)
{
    if (cdata_ == NULL) {
        return;
    }
    easyar_ImageTargetParameters_setUid(cdata_, arg0->get_cdata());
}
inline void ImageTargetParameters::meta(/* OUT */ String * * Return)
{
    if (cdata_ == NULL) {
        *Return = NULL;
        return;
    }
    easyar_String * _return_value_ = NULL;
    easyar_ImageTargetParameters_meta(cdata_, &_return_value_);
    *Return = new String(_return_value_);
}
inline void ImageTargetParameters::setMeta(String * arg0)
{
    if (cdata_ == NULL) {
        return;
    }
    easyar_ImageTargetParameters_setMeta(cdata_, arg0->get_cdata());
}
inline float ImageTargetParameters::scale()
{
    if (cdata_ == NULL) {
        return float();
    }
    float _return_value_ = easyar_ImageTargetParameters_scale(cdata_);
    return _return_value_;
}
inline void ImageTargetParameters::setScale(float arg0)
{
    if (cdata_ == NULL) {
        return;
    }
    easyar_ImageTargetParameters_setScale(cdata_, arg0);
}

inline ImageTarget::ImageTarget(easyar_ImageTarget * cdata)
    :
    Target(static_cast<easyar_Target *>(NULL)),
    cdata_(NULL)
{
    init_cdata(cdata);
}
inline ImageTarget::~ImageTarget()
{
    if (cdata_) {
        easyar_ImageTarget__dtor(cdata_);
        cdata_ = NULL;
    }
}

inline ImageTarget::ImageTarget(const ImageTarget & data)
    :
    Target(static_cast<easyar_Target *>(NULL)),
    cdata_(NULL)
{
    easyar_ImageTarget * cdata = NULL;
    easyar_ImageTarget__retain(data.cdata_, &cdata);
    init_cdata(cdata);
}
inline const easyar_ImageTarget * ImageTarget::get_cdata() const
{
    return cdata_;
}
inline easyar_ImageTarget * ImageTarget::get_cdata()
{
    return cdata_;
}
inline void ImageTarget::init_cdata(easyar_ImageTarget * cdata)
{
    cdata_ = cdata;
    {
        easyar_Target * cdata_inner = NULL;
        easyar_castImageTargetToTarget(cdata, &cdata_inner);
        Target::init_cdata(cdata_inner);
    }
}
inline ImageTarget::ImageTarget()
    :
    Target(static_cast<easyar_Target *>(NULL)),
    cdata_(NULL)
{
    easyar_ImageTarget * _return_value_ = NULL;
    easyar_ImageTarget__ctor(&_return_value_);
    init_cdata(_return_value_);
}
inline void ImageTarget::createFromParameters(ImageTargetParameters * arg0, /* OUT */ ImageTarget * * Return)
{
    easyar_OptionalOfImageTarget _return_value_ = {false, NULL};
    easyar_ImageTarget_createFromParameters(arg0->get_cdata(), &_return_value_);
    *Return = (_return_value_.has_value ? new ImageTarget(_return_value_.value) : NULL);
}
inline void ImageTarget::createFromTargetFile(String * arg0, StorageType arg1, /* OUT */ ImageTarget * * Return)
{
    easyar_OptionalOfImageTarget _return_value_ = {false, NULL};
    easyar_ImageTarget_createFromTargetFile(arg0->get_cdata(), static_cast<easyar_StorageType>(arg1), &_return_value_);
    *Return = (_return_value_.has_value ? new ImageTarget(_return_value_.value) : NULL);
}
inline void ImageTarget::createFromTargetData(Buffer * arg0, /* OUT */ ImageTarget * * Return)
{
    easyar_OptionalOfImageTarget _return_value_ = {false, NULL};
    easyar_ImageTarget_createFromTargetData(arg0->get_cdata(), &_return_value_);
    *Return = (_return_value_.has_value ? new ImageTarget(_return_value_.value) : NULL);
}
inline bool ImageTarget::save(String * arg0)
{
    if (cdata_ == NULL) {
        return bool();
    }
    bool _return_value_ = easyar_ImageTarget_save(cdata_, arg0->get_cdata());
    return _return_value_;
}
inline void ImageTarget::createFromImageFile(String * arg0, StorageType arg1, String * arg2, String * arg3, String * arg4, float arg5, /* OUT */ ImageTarget * * Return)
{
    easyar_OptionalOfImageTarget _return_value_ = {false, NULL};
    easyar_ImageTarget_createFromImageFile(arg0->get_cdata(), static_cast<easyar_StorageType>(arg1), arg2->get_cdata(), arg3->get_cdata(), arg4->get_cdata(), arg5, &_return_value_);
    *Return = (_return_value_.has_value ? new ImageTarget(_return_value_.value) : NULL);
}
inline void ImageTarget::setupAll(String * arg0, StorageType arg1, /* OUT */ ListOfImageTarget * * Return)
{
    easyar_ListOfImageTarget * _return_value_ = NULL;
    easyar_ImageTarget_setupAll(arg0->get_cdata(), static_cast<easyar_StorageType>(arg1), &_return_value_);
    *Return = new ListOfImageTarget(_return_value_);
}
inline float ImageTarget::scale()
{
    if (cdata_ == NULL) {
        return float();
    }
    float _return_value_ = easyar_ImageTarget_scale(cdata_);
    return _return_value_;
}
inline float ImageTarget::aspectRatio()
{
    if (cdata_ == NULL) {
        return float();
    }
    float _return_value_ = easyar_ImageTarget_aspectRatio(cdata_);
    return _return_value_;
}
inline bool ImageTarget::setScale(float arg0)
{
    if (cdata_ == NULL) {
        return bool();
    }
    bool _return_value_ = easyar_ImageTarget_setScale(cdata_, arg0);
    return _return_value_;
}
inline void ImageTarget::images(/* OUT */ ListOfImage * * Return)
{
    if (cdata_ == NULL) {
        *Return = NULL;
        return;
    }
    easyar_ListOfImage * _return_value_ = NULL;
    easyar_ImageTarget_images(cdata_, &_return_value_);
    *Return = new ListOfImage(_return_value_);
}
inline int ImageTarget::runtimeID()
{
    if (cdata_ == NULL) {
        return int();
    }
    int _return_value_ = easyar_ImageTarget_runtimeID(cdata_);
    return _return_value_;
}
inline void ImageTarget::uid(/* OUT */ String * * Return)
{
    if (cdata_ == NULL) {
        *Return = NULL;
        return;
    }
    easyar_String * _return_value_ = NULL;
    easyar_ImageTarget_uid(cdata_, &_return_value_);
    *Return = new String(_return_value_);
}
inline void ImageTarget::name(/* OUT */ String * * Return)
{
    if (cdata_ == NULL) {
        *Return = NULL;
        return;
    }
    easyar_String * _return_value_ = NULL;
    easyar_ImageTarget_name(cdata_, &_return_value_);
    *Return = new String(_return_value_);
}
inline void ImageTarget::setName(String * arg0)
{
    if (cdata_ == NULL) {
        return;
    }
    easyar_ImageTarget_setName(cdata_, arg0->get_cdata());
}
inline void ImageTarget::meta(/* OUT */ String * * Return)
{
    if (cdata_ == NULL) {
        *Return = NULL;
        return;
    }
    easyar_String * _return_value_ = NULL;
    easyar_ImageTarget_meta(cdata_, &_return_value_);
    *Return = new String(_return_value_);
}
inline void ImageTarget::setMeta(String * arg0)
{
    if (cdata_ == NULL) {
        return;
    }
    easyar_ImageTarget_setMeta(cdata_, arg0->get_cdata());
}
inline void ImageTarget::tryCastFromTarget(Target * v, /* OUT */ ImageTarget * * Return)
{
    if (v == NULL) {
        *Return = NULL;
        return;
    }
    easyar_ImageTarget * cdata = NULL;
    easyar_tryCastTargetToImageTarget(v->get_cdata(), &cdata);
    if (cdata == NULL) {
        *Return = NULL;
        return;
    }
    *Return = new ImageTarget(cdata);
}

#ifndef __IMPLEMENTATION_EASYAR_OPTIONALOFIMAGETARGET__
#define __IMPLEMENTATION_EASYAR_OPTIONALOFIMAGETARGET__
static inline easyar_OptionalOfImageTarget OptionalOfImageTarget_to_c(ImageTarget * o)
{
    if (o != NULL) {
        easyar_OptionalOfImageTarget _return_value_ = {true, o->get_cdata()};
        return _return_value_;
    } else {
        easyar_OptionalOfImageTarget _return_value_ = {false, NULL};
        return _return_value_;
    }
}
#endif

#ifndef __IMPLEMENTATION_EASYAR_LISTOFIMAGETARGET__
#define __IMPLEMENTATION_EASYAR_LISTOFIMAGETARGET__
inline ListOfImageTarget::ListOfImageTarget(easyar_ListOfImageTarget * cdata)
    : cdata_(cdata)
{
}
inline ListOfImageTarget::~ListOfImageTarget()
{
    if (cdata_) {
        easyar_ListOfImageTarget__dtor(cdata_);
        cdata_ = NULL;
    }
}

inline ListOfImageTarget::ListOfImageTarget(const ListOfImageTarget & data)
    : cdata_(static_cast<easyar_ListOfImageTarget *>(NULL))
{
    easyar_ListOfImageTarget_copy(data.cdata_, &cdata_);
}
inline const easyar_ListOfImageTarget * ListOfImageTarget::get_cdata() const
{
    return cdata_;
}
inline easyar_ListOfImageTarget * ListOfImageTarget::get_cdata()
{
    return cdata_;
}

inline ListOfImageTarget::ListOfImageTarget(easyar_ImageTarget * * begin, easyar_ImageTarget * * end)
    : cdata_(static_cast<easyar_ListOfImageTarget *>(NULL))
{
    easyar_ListOfImageTarget__ctor(begin, end, &cdata_);
}
inline int ListOfImageTarget::size() const
{
    return easyar_ListOfImageTarget_size(cdata_);
}
inline ImageTarget * ListOfImageTarget::at(int index) const
{
    easyar_ImageTarget * _return_value_ = easyar_ListOfImageTarget_at(cdata_, index);
    easyar_ImageTarget__retain(_return_value_, &_return_value_);
    return new ImageTarget(_return_value_);
}
#endif

#ifndef __IMPLEMENTATION_EASYAR_LISTOFIMAGE__
#define __IMPLEMENTATION_EASYAR_LISTOFIMAGE__
inline ListOfImage::ListOfImage(easyar_ListOfImage * cdata)
    : cdata_(cdata)
{
}
inline ListOfImage::~ListOfImage()
{
    if (cdata_) {
        easyar_ListOfImage__dtor(cdata_);
        cdata_ = NULL;
    }
}

inline ListOfImage::ListOfImage(const ListOfImage & data)
    : cdata_(static_cast<easyar_ListOfImage *>(NULL))
{
    easyar_ListOfImage_copy(data.cdata_, &cdata_);
}
inline const easyar_ListOfImage * ListOfImage::get_cdata() const
{
    return cdata_;
}
inline easyar_ListOfImage * ListOfImage::get_cdata()
{
    return cdata_;
}

inline ListOfImage::ListOfImage(easyar_Image * * begin, easyar_Image * * end)
    : cdata_(static_cast<easyar_ListOfImage *>(NULL))
{
    easyar_ListOfImage__ctor(begin, end, &cdata_);
}
inline int ListOfImage::size() const
{
    return easyar_ListOfImage_size(cdata_);
}
inline Image * ListOfImage::at(int index) const
{
    easyar_Image * _return_value_ = easyar_ListOfImage_at(cdata_, index);
    easyar_Image__retain(_return_value_, &_return_value_);
    return new Image(_return_value_);
}
#endif

}

#endif
