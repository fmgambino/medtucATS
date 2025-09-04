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

// Modo oscuro/claro con LocalStorage
const toggleButton = document.getElementById('theme-toggle');
const logo = document.getElementById('logo');

// Función para actualizar visualmente el tema
function updateTheme(theme) {
  if (theme === 'dark') {
    document.documentElement.setAttribute('data-theme', 'dark');
    toggleButton.textContent = '☀️';
    logo.src = 'https://www.educaciontuc.gov.ar/wp-content/uploads/2024/10/MINISTERIO-DE-EDUCACION_Mesa-de-trabajo-1-2.png';
  } else {
    document.documentElement.removeAttribute('data-theme');
    toggleButton.textContent = '🌙';
    logo.src = 'https://www.educaciontuc.gov.ar/wp-content/uploads/2024/10/mnisteriodeeducacion_bco.webp';
  }
}

// Leer el tema guardado al cargar la página
const savedTheme = localStorage.getItem('theme') || 'light';
updateTheme(savedTheme);

// Escuchar click en el botón
toggleButton.addEventListener('click', () => {
  const currentTheme = document.documentElement.getAttribute('data-theme') === 'dark' ? 'dark' : 'light';
  const newTheme = currentTheme === 'dark' ? 'light' : 'dark';

  updateTheme(newTheme);
  localStorage.setItem('theme', newTheme); // Guardar en localStorage
});
