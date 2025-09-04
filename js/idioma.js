

function idiomaEsp() {
    localStorage.setItem('idioma', 'false');
    URL = "../index.html";
    cambiarVentana(URL);
    check.checked = false;
}

function idiomaEng() {
    localStorage.setItem('idioma', 'true');
    URL = "../en/index.html";
    cambiarVentana(URL);
    check.checked = true;
} 


function cambiarVentana(URL) {
    var xhr = new XMLHttpRequest();
    xhr.open('GET', URL, true);
    xhr.onreadystatechange = function () {
        if (xhr.readyState === 4 && xhr.status === 200) {
            // Redirigir a la nueva ventana
            window.location.href = URL;
        }
    };
    xhr.send();
}