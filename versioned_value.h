#ifndef VERSIONED_VALUE_H
#define VERSIONED_VALUE_H

template <typename V>
class VersionedValue {
public:
    V value;
    int version;

    // ���������� ����� ���� (��� �������)
    VersionedValue() : value(V()), version(0) {}

    // ���������� ����� ����� - ����� ������ ������ ����� �������
    VersionedValue(const V& val, int ver) : value(val), version(ver) {}

    // ������� ������ ��� �����
    void setValue(const V& val, int ver) {
        value = val;
        version = ver;
    }
};

#endif
