#ifndef VERSIONED_VALUE_H
#define VERSIONED_VALUE_H

template <typename V>
class VersionedValue {
public:
    V value;
    int version;

    // קונסטרקטור ברירת מחדל (ללא פרמטרים)
    VersionedValue() : value(V()), version(0) {}

    // קונסטרקטור מותאם אישית - במידה ורוצים להגדיר ערכים מותאמים
    VersionedValue(const V& val, int ver) : value(val), version(ver) {}

    // פונקציה לעדכון ערך וגרסה
    void setValue(const V& val, int ver) {
        value = val;
        version = ver;
    }
};

#endif
