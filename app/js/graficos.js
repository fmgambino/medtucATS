
var baselink;
//tiempo de actualizacion

//variables 
var temperatura = 0;
var viento = 0;
var volumen = 0;
var humedad = 0;
var ph = 0;
var NivelBateria = 0;


 

// console.log('array de datos en graficos');

// console.log('GlobalFechas:', GlobalFechas);
// console.log('GlobalData2:', GlobalData2);
// console.log('GlobalData3:', GlobalData3);


//var gauges = setInterval(pintarGauges(), delay);

function pintarGauges() {
  //datos recibidos en graficos.js desde main.php 
  console.log("datos recibidos en graficos.js");
  console.log("GlobalTemp = ", GlobalTemp);
  console.log("GlobalHumedad = ", GlobalHumedad);
  console.log("GlobalPh = ", GlobalPh);
  console.log("GlobalViento = ", GlobalViento);
  console.log("GlobalVolumen = ", GlobalVolumen);
  console.log("GlobalNivelBateria = ", GlobalNivelBateria);
  //aqui conectar los valores que vienene desde MQTT

  temperatura = parseFloat(GlobalTemp); // funciona ok 
  viento = parseFloat(GlobalViento);
  volumen = parseFloat(GlobalVolumen);
  humedad = parseFloat(GlobalHumedad);
  ph = parseFloat(GlobalPh);
  NivelBateria = parseFloat(GlobalNivelBateria);
  //---------------------------------------------------
  cargaBateria(NivelBateria, 'black', 70, 25);

  document.getElementById('valorTemperatura').innerHTML = temperatura;
  document.getElementById('valorViento').innerHTML = viento;
  document.getElementById('valorVolumen').innerHTML = volumen;
  document.getElementById('valorHumedad').innerHTML = humedad;
  document.getElementById('valorPh').innerHTML = ph;

  gaugemedio('gaugeTemperatura', temperatura, 0, 100, '#EA7577', true);
  gaugemedio('gaugeViento', viento, 0, 200, '#C9E265', true);
  gaugeCompleto('gaugeVolumen', volumen, 0, 100, '#5DB7FE', false, 'Lts');
  gaugeCompleto('gaugeHumedad', humedad, 0, 100, '#F7DC5B', false, '%');
  gaugeCompleto('gaugePh', ph, 0, 15, '#5DB7FE', false, '');
  graficoLinea('grafico1', 'Temperatura', '#EA7577', '°C' , GlobalFechas , GlobalData2 );
  graficoLinea('grafico2', 'Nivel Humedad', '#F7DC5B', '%', GlobalFechas , GlobalData3 );

  console.log("salgo dentro de gauges en graficos.js");
}

function gaugemedio(contenedor, valor, valorMin, valorMax, color, puntero) {

  var chartDom = document.getElementById(contenedor);
  var myChart = echarts.init(chartDom);
  var option;

  option = {
    series: [
      {
        type: 'gauge',
        startAngle: 180,
        endAngle: 0,
        min: valorMin,
        max: valorMax,
        splitNumber: 12,
        itemStyle: {
          color: color,
          shadowColor: 'rgba(0,138,255,0.45)',
          shadowBlur: 10,
          shadowOffsetX: 2,
          shadowOffsetY: 2

        },
        progress: {
          show: true,
          roundCap: false,
          width: 20
        },
        pointer: {
          show: puntero,
          icon: 'path://M2090.36389,615.30999 L2090.36389,615.30999 C2091.48372,615.30999 2092.40383,616.194028 2092.44859,617.312956 L2096.90698,728.755929 C2097.05155,732.369577 2094.2393,735.416212 2090.62566,735.56078 C2090.53845,735.564269 2090.45117,735.566014 2090.36389,735.566014 L2090.36389,735.566014 C2086.74736,735.566014 2083.81557,732.63423 2083.81557,729.017692 C2083.81557,728.930412 2083.81732,728.84314 2083.82081,728.755929 L2088.2792,617.312956 C2088.32396,616.194028 2089.24407,615.30999 2090.36389,615.30999 Z',
          length: '75%',
          width: 5,
          offsetCenter: [0, '15%']
        },
        axisLine: {
          roundCap: false,
          lineStyle: {
            width: 20
          }
        },
        axisTick: {
          show: false
        },
        splitLine: {
          show: false
        },
        axisLabel: {
          show: false
        },
        title: {
          show: false
        },
        detail: {
          show: false,
          offsetCenter: [0, '-10%'],
          width: '10%',
        },

        data: [
          {
            value: valor.toFixed(2)
          }
        ]
      }
    ]
  };
  myChart.resize({
    width: 200,
    height: 170

  });

  myChart.setOption(option);
}

function gaugeCompleto(contenedor, valor, valorMin, valorMax, color, puntero, unidad) {

  var chartDom = document.getElementById(contenedor);
  var myChart = echarts.init(chartDom);
  var option;

  option = {
    series: [
      {
        type: 'gauge',
        startAngle: 270,
        endAngle: -90,
        min: valorMin,
        max: valorMax,
        splitNumber: 12,
        itemStyle: {
          color: color,
          shadowColor: 'rgba(0,138,255,0.45)',
          shadowBlur: 10,
          shadowOffsetX: 2,
          shadowOffsetY: 2
        },
        progress: {
          show: true,
          roundCap: true,
          width: 15
        },
        pointer: {
          show: puntero,
          icon: 'path://M2090.36389,615.30999 L2090.36389,615.30999 C2091.48372,615.30999 2092.40383,616.194028 2092.44859,617.312956 L2096.90698,728.755929 C2097.05155,732.369577 2094.2393,735.416212 2090.62566,735.56078 C2090.53845,735.564269 2090.45117,735.566014 2090.36389,735.566014 L2090.36389,735.566014 C2086.74736,735.566014 2083.81557,732.63423 2083.81557,729.017692 C2083.81557,728.930412 2083.81732,728.84314 2083.82081,728.755929 L2088.2792,617.312956 C2088.32396,616.194028 2089.24407,615.30999 2090.36389,615.30999 Z',
          length: '75%',
          width: 15,
          offsetCenter: [0, '5%']
        },
        axisLine: {

          roundCap: true,
          lineStyle: {
            width: 15
          }
        },
        axisTick: {
          show: false,
          splitNumber: 2,
          lineStyle: {
            width: 2,
            color: '#999'
          }
        },
        splitLine: {
          show: false,
          length: 12,
          lineStyle: {
            width: 3,
            color: '#999'
          }
        },
        axisLabel: {
          show: false,
          distance: 30,
          color: '#999',
          fontSize: 20
        },
        title: {
          show: false
        },
        detail: {

          width: '40%',
          lineHeight: 40,
          height: 20,
          borderRadius: 8,
          offsetCenter: [0, '-10%'],
          valueAnimation: true,
          formatter: function (value, unit) {
            return '{value|' + value.toFixed(1) + '}{unit|' + unidad + '}';
          },
          rich: {

            value: {
              fontSize: 25,
              fontWeight: 'bolder',
              color: '#fff'
            },
            unit: {
              fontSize: 15,
              color: '#fff',
              padding: [0, 0, 0, 0]
            }
          }
        },
        data: [
          {
            value: valor,
            unit: unidad
          }
        ]
      }
    ]
  };

  myChart.resize({
    width: 200,
    height: 170
  });

  myChart.setOption(option);
}

function graficoLinea(contenedor, titulo, color, unidad , ArrayFechas , ArrayDatos) {


  var chartDom = document.getElementById(contenedor);
  var myChart = echarts.init(chartDom);
  var option;

  option = {
    title: {
      text: titulo,
      left: 'left',
      textStyle: {
        color: '#fff'
      },
    },
    tooltip: {
      trigger: 'axis',
      axisPointer: {
        type: 'cross',
        label: {
          backgroundColor: '#6a7985'
        }
      }
    },
    legend: {
      type: "plain",
      textStyle: {
        color: '#fff'
      }
    },

    grid: {
      left: '3%',
      right: '4%',
      bottom: '3%',
      containLabel: true
    },
    xAxis: [
      {
        type: 'category',
        boundaryGap: false,
        axisLabel: {
          color: '#fff'
        },
        data: ArrayFechas
      }
    ],
    yAxis: [
      {
        type: 'value',
        axisLabel: {
          formatter: '{value} ' + unidad,
          color: '#fff'
        }
      }
    ],
    series: [
      {
        name: "", //titulo,
        type: 'line',
        smooth: true, // efecto redondeo para la grafica
        color: color,
        stack: 'Total',
        areaStyle: {
          color: color,
        },
        emphasis: {
          focus: 'series'
        },
        data: ArrayDatos
      }
    ]
  };

  option && myChart.setOption(option);
}

function cargaBateria(valor, colorTexto, rango1, rango2) {


  document.getElementById("valorBateria").innerHTML = valor;
  document.getElementById("bateria").style.width = valor + '%';
  document.getElementById("bateria").style.color = colorTexto;
  if (valor > rango1) {
    document.getElementById("bateria").style.background = 'rgb(44, 255, 0)';
  } else {
    if (valor > rango2) {
      document.getElementById("bateria").style.background = '#F7DC5B';
    }
    else {
      document.getElementById("bateria").style.background = '#f44336';
    }
  }

}

var img1 = "images/cancelblanco.png";
var img2 = "images/checkblanco.png";

function sw1_change() { // esta funcion esta ok
  var imagen1 = document.getElementById('icono1');
  if ($('#display_sw1').is(":checked")) {
    console.log("ingrese en sw1_change ok");
    client.publish(device_topic + 'actions/sw1', "1"); //Valor que envio al broker             
    imagen1.src = img2;
    imagen1.classList.remove("hc-icono-cancel");
    imagen1.classList.add("hc-icono-check");
  } else {
    console.log("ingrese en sw1_change else");
    client.publish(device_topic + 'actions/sw1', "0");
    imagen1.src = img1;
    imagen1.classList.remove("hc-icono-check");
    imagen1.classList.add("hc-icono-cancel");
  }

}
