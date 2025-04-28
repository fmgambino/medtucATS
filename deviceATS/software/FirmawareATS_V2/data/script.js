async function fetchData() {
  try {
    const response = await fetch('/data');
    const data = await response.json();

    document.getElementById('temp').textContent = `${data.temperatura} °C`;
    document.getElementById('hum').textContent = `${data.humedad} %`;
    document.getElementById('air').textContent = `${data.calidadAire} ppm`;
    document.getElementById('fuel').textContent = `${data.nafta} %`;
    document.getElementById('gen').textContent = data.generador ? 'Encendido' : 'Apagado';
  } catch (error) {
    console.error('Error obteniendo datos:', error);
  }
}

// Actualizar datos cada 2 segundos
setInterval(fetchData, 2000);
fetchData();

// Modo oscuro/claro
const toggleButton = document.getElementById('theme-toggle');
const logo = document.getElementById('logo');

toggleButton.addEventListener('click', () => {
  const currentTheme = document.documentElement.getAttribute('data-theme');

  if (currentTheme === 'dark') {
    document.documentElement.removeAttribute('data-theme');
    toggleButton.textContent = '🌙';
    logo.src = 'https://www.educaciontuc.gov.ar/wp-content/uploads/2024/10/mnisteriodeeducacion_bco.webp';
  } else {
    document.documentElement.setAttribute('data-theme', 'dark');
    toggleButton.textContent = '☀️';
    logo.src = 'https://www.educaciontuc.gov.ar/wp-content/uploads/2024/10/MINISTERIO-DE-EDUCACION_Mesa-de-trabajo-1-2.png';
  }
});
