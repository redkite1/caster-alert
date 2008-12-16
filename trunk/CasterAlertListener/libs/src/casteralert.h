#ifndef CASTERALERT_H
#define CASTERALERT_H

#include <QList>
#include <QString>
#include <QMetaType>
#include <QDataStream>

class CasterAlert
{    

public:
    CasterAlert();
    ~CasterAlert();

    void setFrom(const QString f);
    QString getFrom() const;
    void addTo(const QString newTo);
    QList<QString> getTo() const;

    friend QDataStream & operator<<( QDataStream &out, const CasterAlert &ca );
    friend QDataStream & operator>>( QDataStream &in, CasterAlert &ca );

private:
    QString from;
    QList<QString> to;  // Faire que l'envoyeur envoit a pls personne ou que le listener puisse ecouter plusieurs personne? ou les deux?
};

//Q_DECLARE_METATYPE(CasterAlert)

#endif // CASTERALERT_H
