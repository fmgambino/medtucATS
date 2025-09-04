	// Sticky Navbar
    let header = document.querySelector('header');
    let menu = document.querySelector('#menu-icon');
    let navbar = document.querySelector('.navbar');
     
     
    window.addEventListener('scroll', () => {
        header.classList.toggle('shadow', window.scrollY > 0);
    });
     
    menu.onclick = () => {
        navbar.classList.toggle('active');
    }
    window.onscroll = () => {
        navbar.classList.remove('active');
    }
     
    // Dark Mode Web
    let darkmode = document.querySelector('#darkmode');
    let imagenSvg =  document.getElementById('svgDarkmode');
    

    darkmode.onclick = () => {
        if(darkmode.classList.contains('bx-moon')){
            darkmode.classList.replace('bx-moon','bx-sun');
            localStorage.setItem('dark-mode', 'true');  
            console.log(localStorage);
            document.body.classList.add('active');
            console.log("Activo Dark");
            
            
            imgchange.src = "/image/logoYakuLigth.png"
            console.log('entre al if');
            console.log(imagenSvg);
            imagenSvg.classList.replace('svgDefecto', 'svgDark');


        }else{
            darkmode.classList.replace('bx-sun','bx-moon');
            localStorage.setItem('dark-mode', 'false');
            console.log(localStorage);
            document.body.classList.remove('active');
            console.log("Activo Ligth");
           
            imgchange.src = "/image/logoYakuDark.png";
            console.log('entre al else');
            console.log(imagenSvg);
            imagenSvg.classList.replace('svgDark', 'svgDefecto');
           
        }

    }

    if(localStorage.getItem('dark-mode') === 'true'){
        darkmode.classList.replace('bx-moon','bx-sun');
        document.body.classList.add('active');
        imgchange.src = "/image/logoYakuLigth.png";
        imagenSvg.classList.replace('svgDefecto', 'svgDark');

    } else {
        document.body.classList.remove('active'); 
    }