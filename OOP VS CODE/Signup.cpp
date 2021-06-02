#include <CkMailMan.h>
#include <CkEmail.h>

void ChilkatSample(void)
    {
    // This example requires the Chilkat API to have been previously unlocked.
    // See Global Unlock Sample for sample code.

    // The mailman object is used for sending and receiving email.
    CkMailMan mailman;

    // Set the SMTP server.
    mailman.put_SmtpHost("smtp.chilkatsoft.com");

    // Set the SMTP login/password (if required)
    mailman.put_SmtpUsername("myUsername");
    mailman.put_SmtpPassword("myPassword");

    // Create a new email object
    CkEmail email;

    email.put_Subject("This is a test");
    email.put_Body("This is a test");
    email.put_From("Chilkat Support <support@chilkatsoft.com>");
    bool success = email.AddTo("Chilkat Admin","admin@chilkatsoft.com");
    // To add more recipients, call AddTo, AddCC, or AddBcc once per recipient.

    // Call SendEmail to connect to the SMTP server and send.
    // The connection (i.e. session) to the SMTP server remains
    // open so that subsequent SendEmail calls may use the
    // same connection.  
    success = mailman.SendEmail(email);
    if (success != true) {
        std::cout << mailman.lastErrorText() << "\r\n";
        return;
    }

    // Some SMTP servers do not actually send the email until 
    // the connection is closed.  In these cases, it is necessary to
    // call CloseSmtpConnection for the mail to be  sent.  
    // Most SMTP servers send the email immediately, and it is 
    // not required to close the connection.  We'll close it here
    // for the example:
    success = mailman.CloseSmtpConnection();
    if (success != true) {
        std::cout << "Connection to SMTP server not closed cleanly." << "\r\n";
    }

    std::cout << "Mail Sent!" << "\r\n";
    }