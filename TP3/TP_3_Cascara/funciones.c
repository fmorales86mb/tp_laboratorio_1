#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

int agregarPelicula(EMovie movie)
{
    return 0;
}

int borrarPelicula(EMovie movie)
{
    return 0;
}

void generarPagina(EMovie lista[], char nombre[])
{

}

void generarTextoHtml(char* html, char urlImagen[], char titulo[], char genero[], int puntaje, int duracion, char sinopsis[])
{
    char htmlBase[10000]={"<!DOCTYPE html><html lang='en'><head>    <meta charset='utf-8'>    <meta http-equiv='X-UA-Compatible' content='IE=edge'>    <meta name='viewport' content='width=device-width, initial-scale=1'>        <title>Lista peliculas</title>        <link href='css/bootstrap.min.css' rel='stylesheet'>        <link href='css/custom.css' rel='stylesheet'></head><body>    <div class='container'>        <div class='row'>				<!-- Repetir esto para cada pelicula -->            <article class='col-md-4 article-intro'>                <a href='#'>                    <img class='img-responsive img-rounded' src='%s' alt=''>                   <!--  <img class='img-responsive img-rounded' src='http://ia.media-imdb.com/images/M/MV5BMjA5NTYzMDMyM15BMl5BanBnXkFtZTgwNjU3NDU2MTE@._V1_UX182_CR0,0,182,268_AL_.jpg' alt=''> -->                </a>                <h3>                    <a href='#'>%s</a>                </h3>				<ul>					<li>Género: %s</li>					<li>Puntaje: %d</li>					<li>Duración: %d</li>									</ul>                <p>%s</p>            </article>			<!-- Repetir esto para cada pelicula --> 			        </div>            </div>    <script src='js/jquery-1.11.3.min.js'></script><script src='js/bootstrap.min.js'></script>		<script src='js/ie10-viewport-bug-workaround.js'></script>		<script src='js/holder.min.js'></script></body></html>"};
    char htmlCompleto[20000];
    //sprintf(htmlCompleto, htmlBase, urlImagen, titulo, genero, )

}
