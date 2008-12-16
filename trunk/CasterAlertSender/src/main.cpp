#include <QApplication>
#include "casteralertsenderimpl.h"

int main(int argc, char ** argv)
{
    QApplication app( argc, argv );
    CasterAlertSenderImpl win;

    // Pour que le compilateur puisse utiliser la classe CasterAlert comme une classe connue ... :-/ (un peu apprenti sorcier là :-p )
    //qRegisterMetaType<CasterAlert>("CasterAlert");
    //qRegisterMetaTypeStreamOperators<CasterAlert>("CasterAlert");

    win.show();
    app.connect( &app, SIGNAL( lastWindowClosed() ), &app, SLOT( quit() ) );

    return app.exec();
}
