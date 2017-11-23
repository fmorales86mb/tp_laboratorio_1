
int soloLetras(char str[])
{
    int retorno = 0;
    int i=0;
    char caracter;

    while (str[i]!='\0')
    {
        caracter = str[i];
        if (!((caracter>= 'A' && caracter<= 'Z') || (caracter>= 'a' && caracter<= 'z') || (caracter == ' ')))
        {
            retorno= -1;
            break;
        }
        i++;
    }

    return retorno;
}

int soloNumeros(char str[])
{
    int retorno = 0;
    int i=0;
    char caracter;

    while (str[i]!='\0')
    {
        caracter = str[i];
        if (!(caracter>= '0' && caracter<= '9'))
        {
            retorno= -1;
            break;
        }
        i++;
    }

    return retorno;
}

int soloAlfanumerico(char str[])
{
    int retorno = 0;
    int i=0;
    char caracter;

    while (str[i]!='\0')
    {
        caracter = str[i];
        if (!(caracter>= '0' && caracter<= '9')||
            (caracter>= 'A' && caracter<= 'Z') ||
            (caracter>= 'a' && caracter<= 'z') ||
            (caracter == ' '))
        {
            retorno= -1;
            break;
        }
        i++;
    }

    return retorno;
}

int soloTelefono(char str[])
{
    int retorno = 0;
    int i=0;
    char caracter;

    while (str[i]!='\0')
    {
        caracter = str[i];
        if (!(caracter>= '0' && caracter<= '9') || (caracter =='-'))
        {
            retorno= -1;
            break;
        }
        i++;
    }

    return retorno;
}

