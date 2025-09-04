let progresBar = document.querySelector(".progresTemp");
let valorContenedor = document.querySelector(".valorTemp");
let progresNivel = document.querySelector(".progresNivel");
let valorNivel = document.querySelector(".valorNivel");
let progresEspuma = document.querySelector(".progresEspuma");
let valorEspuma = document.querySelector(".valorEspuma");

let valorProgreso = 0;
let Nivelinicial = 0;
let EspumaInicial = 0;

let valorFinalProgreso = 89;
let valorFinalNivel = 39;
let valorFinalEspuma = 50;

let velocidad = 0.1;

let progreso = setInterval(() => {
    valorProgreso++;
    /*console.log('valor de progreso =' + valorProgreso);*/
    valorContenedor.textContent = valorProgreso + '°C';
    let desplazamiento = valorProgreso * 3.6;
    /*console.log(desplazamiento);*/
    progresBar.style.background = 'conic-gradient( #ff8080 ' + desplazamiento + 'deg , #2d5e8f ' + desplazamiento + 'deg)';
    /*console.log(progresBar.style.background);*/
    if (valorProgreso == valorFinalProgreso) {
        clearInterval(progreso);
    }
}, velocidad);

let Nivel = setInterval(() => {
    Nivelinicial++;
    /*console.log('valor de progreso =' + valorProgreso);*/
    valorNivel.textContent = Nivelinicial + '%';
    let desplazamientoNivel = Nivelinicial * 3.6;
    /*console.log(desplazamiento);*/
    progresNivel.style.background = 'conic-gradient( #a0e6de ' + desplazamientoNivel + 'deg , #2d5e8f ' + desplazamientoNivel + 'deg)';
    /*console.log(progresBar.style.background);*/
    if (Nivelinicial == valorFinalNivel) {
        clearInterval(Nivel);
    }
}, velocidad);

let Espuma = setInterval(() => {
    EspumaInicial++;
    /*console.log('valor de progreso =' + valorProgreso);*/
    valorEspuma.textContent = EspumaInicial + 'cm';
    let desplazamientoEspuma = EspumaInicial * 3.6;
    /*console.log(desplazamiento);*/
    progresEspuma.style.background = 'conic-gradient( #ffbd59 ' + desplazamientoEspuma + 'deg , #2d5e8f ' + desplazamientoEspuma + 'deg)';
    /*console.log(progresBar.style.background);*/
    if (EspumaInicial == valorFinalEspuma) {
        clearInterval(Espuma);
    }
}, velocidad);