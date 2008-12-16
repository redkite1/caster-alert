#include "casteralert.h"

CasterAlert::CasterAlert()
{
}

CasterAlert::~CasterAlert()
{
}

void CasterAlert::setFrom(const QString f)
{
    from = f;
}

QString CasterAlert::getFrom() const
{
    return from;
}

void CasterAlert::addTo(const QString newTo)
{
    to.append(newTo);
}

QList<QString> CasterAlert::getTo() const
{
    return to;
}

QDataStream & operator<<( QDataStream &out, const CasterAlert &ca )
{
    out << ca.from;
    out << ca.to;

    return out;
}

QDataStream & operator>>( QDataStream &in, CasterAlert &ca )
{
    in >> ca.from;
    in >> ca.to;

    return in;
}
