#include <extend.api>

/* The following is really a bit lame, you should consider replacing these
   macros with something that really tests for alphas and digits (for
   example, this ISALPHA() won't be much use in many European countries).
*/

#define ISALPHA( c ) (((c) >= 'a' && (c) <= 'z') || ((c) >= 'A' && (c) <= 'Z'))
#define ISDIGIT( c ) ((c) >= '0' && (c) <= '9')

CLIPPER IsFormat()
{
    int iOk = FALSE;
    char *pszString;
    char *pszFormat;

    if ( PCOUNT == 2 && ISCHAR( 1 ) && ISCHAR( 2 ) )
    {
        pszString = _parc( 1 );
        pszFormat = _parc( 2 );
        iOk       = TRUE;

        while ( *pszString && *pszFormat && iOk )
        {
            switch ( *pszFormat )
            {
                case 'n' :
                case 'N' :
                case '9' : { iOk = ISDIGIT( *pszString ); break; }
                case 'a' :
                case 'A' :
                case 'c' :
                case 'C' : { iOk = ISALPHA( *pszString ); break; }
                case ' ' : { iOk = ( *pszString == ' ' ); break; }
                default  : { iOk = ( *pszFormat == '?' ); break; }
            }

            ++pszString;
            ++pszFormat;
        }
    }

    _retl( iOk );
}
