#include <QApplication>
#include "casteralertsenderimpl.h"

int main(int argc, char ** argv)
{
    QApplication app( argc, argv );
    // Before instanciating CasterAlertListenerImpl... otherwise it can't work properly
    QApplication::setOrganizationName("CasterInfo");
    QApplication::setOrganizationDomain("casterinfo.be");
    QApplication::setApplicationName("Caster Alert Sender");
    CasterAlertSenderImpl win;

    // Pour que le compilateur puisse utiliser la classe CasterAlert comme une classe connue ... :-/ (un peu apprenti sorcier là :-p )
    //qRegisterMetaType<CasterAlert>("CasterAlert");
    //qRegisterMetaTypeStreamOperators<CasterAlert>("CasterAlert");

    win.show();
    app.connect( &app, SIGNAL( lastWindowClosed() ), &app, SLOT( quit() ) );

    return app.exec();
}
