
let progresBar = document.querySelector(".progresTemp");
let valorContenedor = document.querySelector(".valorTemp");
let progresNivel = document.querySelector(".progresNivel");
let valorNivel = document.querySelector(".valorNivel");
let progresEspuma = document.querySelector(".progresEspuma");
let valorEspuma = document.querySelector(".valorEspuma");

let valorProgreso = 0;
let Nivelinicial = 0;
let EspumaInicial = 0;

let valorFinalProgreso = 25;
let valorFinalNivel = 39;
let valorFinalEspuma = 50;

let velocidad = 50;

let gTemp = 10;
let gNivel = 20;
let gEspuma = 0;

let progreso = setInterval(() => { 

    if(valorProgreso < gTemp){
        valorProgreso++;        
    }
    if(valorProgreso > gTemp){
        valorProgreso--;        
    }        
    valorContenedor.textContent = valorProgreso + '°C';
    let desplazamiento = valorProgreso * 3.6;    
    progresBar.style.background = 'conic-gradient( #ff8080 ' + desplazamiento + 'deg , #2d5e8f ' + desplazamiento + 'deg)';    
    
}, velocidad);

let Nivel = setInterval(() => {
    console.log('valor de melasa =' + gNivel);    
    if(Nivelinicial < gNivel){
        Nivelinicial++;        
    }
    if(Nivelinicial > gNivel){
        Nivelinicial--;        
    }  
    valorNivel.textContent = Nivelinicial + '%';
    let desplazamientoNivel = Nivelinicial * 3.6;    
    progresNivel.style.background = 'conic-gradient( #a0e6de ' + desplazamientoNivel + 'deg , #2d5e8f ' + desplazamientoNivel + 'deg)';
        
}, velocidad);

