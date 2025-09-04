<main class=" container-fluid" style="overflow-y:scroll;">

  <div class="">

    <!-- Actuadores-->
    <div class="row">
      <div class="col-12 col-md-4 hc-box-a">
        <div class="mdl-card  trending">
          <div class="mdl-card__supporting-text">

            <ul class="mdl-list">

              <li class="mdl-list__item">
                <span class="mdl-list__item-primary-content list__item-text">Bomba Anti-Derrame</span>
                <span class="mdl-list__item-secondary-content" style="padding-top: 6px;">
                  <!-- SWITCH-->
                  <label class="switch mr-2">
                    <input onchange="sw1_change()" type="checkbox" id="display_sw1">
                    <span class="slider round"></span>
                  </label>
                </span>
                <img src="<?php echo base_url('images/cancel.png') ?>" class="hc-icono-cancel" id="icono1" alt="">
              </li>
              <div class="row ">
                <!-- TEMP -->
                <div class="col-12 ">
                  <div class="  weather">
                    <div class=" mdl-card--expand color-azul-1 form-inline">
                      <div class="col-6 pt-3 pb-3 pl-0 pr-0">
                        <div class="mdl-card__title">
                          <h2 class="mdl-card__title-text">Temperatura</h2>
                          <img src="<?php echo base_url('images/iconoTemp.svg') ?>" class="icono">
                        </div>
                        <div class="mdl-card__supporting-text mdl-card--expand hc-contenedor row">
                          <p id="display_tempamb" class="weather-temperature hc-valor">--</p>
                          <h1 class="hc-unidades">°C</h1>
                        </div>
                      </div>
                      <div class="col-6 pt-3 pb-3 pl-0 pr-0">
                        <div class="progres-circular progresTemp">
                          <div class="progres-valor valorTemp">--</div>
                        </div>
                      </div>
                    </div>
                  </div>
                </div>
                <!-- HUM-->
                <div class="col-12 ">
                  <div class="  weather">
                    <div class=" mdl-card--expand color-azul-1 form-inline">
                      <div class="col-6 pt-3 pb-3 pl-0 pr-0">
                        <div class="mdl-card__title">
                          <h2 class="mdl-card__title-text">Nivel Melasa</h2>
                          <img src="<?php echo base_url('images/iconoWater.svg') ?>" class="icono">
                        </div>
                        <div class="mdl-card__supporting-text mdl-card--expand hc-contenedor row">
                          <p id="display_tempamb" class="weather-temperature hc-valor">--</p>
                          <h1 class="hc-unidades">%</h1>
                        </div>
                      </div>
                      <div class="col-6 pt-3 pb-3 pl-0 pr-0">
                        <div class="progres-circular progresNivel">
                          <div class="progres-valor valorNivel">--</div>
                        </div>
                      </div>
                    </div>
                  </div>
                </div>
                <!-- H2O -->
                <div class="col-12 ">
                  <div class="  weather">
                    <div class=" mdl-card--expand color-azul-1 form-inline">
                      <div class="col-6 pt-3 pb-3 pl-0 pr-0">
                        <div class="mdl-card__title">
                          <h2 class="mdl-card__title-text mr-1">Nivel Espuma</h2>
                          <img src="<?php echo base_url('images/iconoNube.svg') ?>" class="icono">
                        </div>
                        <div class="mdl-card__supporting-text mdl-card--expand hc-contenedor row">
                          <p id="display_tempamb" class="weather-temperature hc-valor">--</p>
                          <h1 class="hc-unidades">cm</h1>
                        </div>
                      </div>
                      <div class="col-6 pt-3 pb-3 pl-0 pr-0">
                        <div class="progres-circular progresEspuma">
                          <div class="progres-valor valorEspuma">--</div>
                        </div>
                      </div>
                    </div>
                  </div>
                </div>

              </div>
            </ul>
          </div>
        </div>
      </div>

      <div class="col-12 col-md-8 hc-box-b">
        <!-- Table-->
        <!-- Line chart-->
        <div class="">
          <div class=" mdl-shadow--2dp line-chart">
            <div class="mdl-card__title">
              <h2 class="mdl-card__title-text hc-color-text-blanco">Nivel CO2</h2>
            </div>
            <div class="mdl-card__supporting-text">
              <canvas id="my_chart" width="auto" height="300"></canvas>
            </div>
          </div>
        </div>
        <!-- Table-->

        <!-- Table-->
        <!-- Line chart 2-->
        <div class="">
          <div class=" mdl-shadow--2dp line-chart">
            <div class="mdl-card__title">
              <h2 class="mdl-card__title-text hc-color-text-blanco">Tem. Ambiente</h2>
            </div>
            <div class="mdl-card__supporting-text">
              <canvas id="my_chart2" width="auto" height="300"></canvas>
            </div>
          </div>
        </div>
        <!-- Table-->


      </div>
    </div>
  </div>
  </div>
</main>
<script src="<?php echo base_url('js/progresbarlmz.js') ?>"></script>
<script type="text/javascript">
  var css_file = document.createElement("link");
  var widgetUrl = location.href;
  css_file.setAttribute("rel", "stylesheet");
  css_file.setAttribute("type", "text/css");
  css_file.setAttribute("href", 'https://s.bookcdn.com/css/w/booked-wzs-widget-prime-days.css?v=0.0.1');
  document.getElementsByTagName("head")[0].appendChild(css_file);

  function setWidgetData_99676(data) {
    if (typeof(data) != 'undefined' && data.results.length > 0) {
      for (var i = 0; i < data.results.length; ++i) {
        var objMainBlock = document.getElementById('m-booked-prime-days-99676');
        if (objMainBlock !== null) {
          var copyBlock = document.getElementById('m-bookew-weather-copy-' + data.results[i].widget_type);
          objMainBlock.innerHTML = data.results[i].html_code;
          if (copyBlock !== null) objMainBlock.appendChild(copyBlock);
        }
      }
    } else {
      alert('data=undefined||data.results is empty');
    }
  }
  var widgetSrc = "https://widgets.booked.net/weather/info?action=get_weather_info;ver=7;cityID=37228;type=6;scode=124;ltid=3457;domid=582;anc_id=60187;countday=4;cmetric=1;wlangID=4;color=ffffff;wwidth=250;header_color=ffffff;text_color=ffffff;link_color=ffffff;border_form=1;footer_color=ffffff;footer_text_color=ffffff;transparent=1;v=0.0.1";
  widgetSrc += ';ref=' + widgetUrl;
  widgetSrc += ';rand_id=99676';
  var weatherBookedScript = document.createElement("script");
  weatherBookedScript.setAttribute("type", "text/javascript");
  weatherBookedScript.src = widgetSrc;
  document.body.appendChild(weatherBookedScript)
</script><!-- weather widget end -->
<script>
  var ctx = document.getElementById('my_chart').getContext('2d');
  var ctx2 = document.getElementById('my_chart2').getContext('2d');

  var myChart = new Chart(ctx, {
    type: 'line',
    data: {
      labels: [<?php echo $dates ?>],
      datasets: [{
        label: '°C',        
        data: [<?php echo $co2s ?>],        
        backgroundColor: '#ff8080',
        borderColor: '#d6555c',
        borderWidth: 2
      }]
    },

    options: {
      maintainAspectRatio: false,
      legend: {
                labels: {
                    fontColor: "white",
                    fontSize: 18
                }
            },     
      scales: {
        xAxes: [{          
          ticks: {
            beginAtZero: true,           
            fontColor: "white"          
          },
          gridLines: {
            display: true,
            color: "#FFFFFF"
          }
        }],
        yAxes: [{
          ticks: {
            beginAtZero: false,
            fontColor: "white"
          },
          gridLines: {
            display: true,
            color: "#FFFFFF"
          }
        }]
      }
    }
  });


  var myChart2 = new Chart(ctx2, {
    type: 'line',
    data: {
      labels: [<?php echo $dates ?>],
      datasets: [{
        label: '%',
        data: [<?php echo $hums ?>],
        backgroundColor: [
          '#ffd18b',
        ],
        borderColor: [
          '#ffbd59',
        ],
        borderWidth: 1
      }]
    },
    options: {
      maintainAspectRatio: false,
      legend: {
                labels: {
                    fontColor: "white",
                    fontSize: 18
                }
            },     
      scales: {
        xAxes: [{          
          ticks: {
            beginAtZero: true,           
            fontColor: "white"          
          },
          gridLines: {
            display: true,
            color: "#FFFFFF"
          }
        }],
        yAxes: [{
          ticks: {
            beginAtZero: false,
            fontColor: "white"
          },
          gridLines: {
            display: true,
            color: "#FFFFFF"
          }
        }]
      }
    }
  });  

  const options = {
    connectTimeout: 1000,
    // Authentication
    clientId: 'esp32_fmg_' + Math.floor((Math.random() * 1000000) + 1),
    username: '<?php echo MQTT_USER; ?>',
    password: '<?php echo MQTT_PASSWORD; ?>',
    keepalive: 60,
    clean: true,
  }

  // WebSocket connect url
  // const WebSocket_URL = 'wss://broker.emqx.io:8084/mqtt';
  // const client = mqtt.connect(WebSocket_URL, options)

  // var device_topic = '<?php echo ROOT_TOPIC . "/" . $_SESSION['selected_topic'] . "/" ?>';
  // client.on('connect', () => {
  //   console.log('Conexión Exitosa ^_^');

  //   client.subscribe(device_topic + "data", {
  //     qos: 0
  //   }, (error) => {
  //     if (error) {
  //       console.log("Error al Suscribir");
  //     } else {
  //       console.log("Suscrito al Broker con Exito!");
  //       console.log("Proyecto de Inversión");
  //       console.log("San Miguel de Tucumán - Tucumán - Argentina");
  //       console.log("by ELECTRÓNICA GAMBINO");
  //       console.log("2022");
  //     }

  //   })
  // })

  var contCo2 = 0;
  var contcdtv = 0;

  var sumadorA = 0;
  var sumadorB = 0;
  var sumadorC = 0;
  var co2, cdtv;

  client.on('message', (topic, message) => {
    console.log('Msg desde el topico: ', topic, ' ----> ', message.toString());

    if (topic == device_topic + "data") {
      var splitted = message.toString().split(",");

      var sumco2 = splitted[0];
      var tempamb = splitted[1];
      var hum = splitted[2];
      var ph = splitted[3];
      var niv = splitted[4];


      var switch1 = splitted[5];
      var switch2 = splitted[6];
      var switch3 = splitted[7];
      var sumcdtv = splitted[8];

      var estado1 = splitted[9];;
      var estado2 = splitted[10];
      var estado3 = splitted[11];

      var numEntero = parseInt(sumco2);
      sumadorA = sumadorA + numEntero;
      contCo2++;
      if (contCo2 == 1) {
        co2 = numEntero
      }
      if (contCo2 == 10) {
        co2 = sumadorA / 10;
        contCo2 = 0;
        sumadorA = 0;
        console.log("valor promedio de co2 calculado");
        console.log(co2);
      }

      console.log("valor que llega de conductividad");
      console.log(sumcdtv);
      var numcdtv = parseFloat(sumcdtv);
      console.log("valor de cdtv ");
      console.log(numcdtv);
      if (numcdtv != "NaN") {
        sumadorB = sumadorB + numcdtv;
        contcdtv++;
        if (contcdtv == 1) {
          cdtv = numcdtv;
        }
        if (contcdtv == 5) {
          cdtv = sumadorB / 5;
          contcdtv = 0;
          sumadorB = 0;
          console.log("valor promedio de cdtv calculado");
          console.log(cdtv);
        }
      }



      $("#display_co2").html(co2);
      $("#display_tempamb").html(tempamb);
      $("#display_hum").html(hum);
      $("#display_ph").html(ph);
      $("#display_cdtv").html(cdtv);



      if (niv == 0) {
        $("#display_niv").html("ALTO");
      } else {
        $("#display_niv").html("OPTIMO");
      }

      if (switch1 == "1") {
        $("#display_sw1").prop('checked', true);

      } else {
        $("#display_sw1").prop('checked', "");
      }

      if (switch2 == "1") {
        $("#display_sw2").prop('checked', true);
      } else {
        $("#display_sw2").prop('checked', "");
      }

      if (switch3 == "1") {
        $("#display_sw3").prop('checked', true);
      } else {
        $("#display_sw3").prop('checked', "");
      }

      var img3 = "<?php echo base_url('images/cancelblanco.png') ?>";
      var img4 = "<?php echo base_url('images/checkblanco.png') ?>";

      var imagen4 = document.getElementById('icono1');
      var imagen5 = document.getElementById('icono2');
      var imagen6 = document.getElementById('icono3');

      console.log("ingrese estado = 1");

      if (estado1 == "1") {
        console.log("ingrese estado1 = 1");
        imagen4.src = img4;
        imagen4.classList.remove("hc-icono-cancel");
        imagen4.classList.add("hc-icono-check");
      } else {
        console.log("ingrese estado1 = 0");
        imagen4.src = img3;
        imagen4.classList.remove("hc-icono-check");
        imagen4.classList.add("hc-icono-cancel");
      }

      if (estado2 == "1") {
        imagen5.src = img4;
        imagen5.classList.remove("hc-icono-cancel");
        imagen5.classList.add("hc-icono-check");
      } else {
        imagen5.src = img3;
        imagen5.classList.remove("hc-icono-check");
        imagen5.classList.add("hc-icono-cancel");
      }

      if (estado3 == "1") {
        imagen6.src = img4;
        imagen6.classList.remove("hc-icono-cancel");
        imagen6.classList.add("hc-icono-check");
      } else {
        imagen6.src = img3;
        imagen6.classList.remove("hc-icono-check");
        imagen6.classList.add("hc-icono-cancel");
      }

    }
  })

  client.on('reconnect', (error) => {
    console.log('reconnecting:', error);
  })

  client.on('error', (error) => {
    console.log('Connect Error:', error);
  })

  var img1 = "<?php echo base_url('images/cancelblanco.png') ?>";
  var img2 = "<?php echo base_url('images/checkblanco.png') ?>";

  function sw1_change() {
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

  function sw2_change() {
    var imagen2 = document.getElementById('icono2');
    if ($('#display_sw2').is(":checked")) {
      client.publish(device_topic + 'actions/sw2', "1");
      imagen2.src = img2;
      imagen2.classList.remove("hc-icono-cancel");
      imagen2.classList.add("hc-icono-check");
    } else {
      client.publish(device_topic + 'actions/sw2', "0");
      imagen2.src = img1;
      imagen2.classList.remove("hc-icono-check");
      imagen2.classList.add("hc-icono-cancel");
    }
  }

  function sw3_change() {
    var imagen3 = document.getElementById('icono3');
    if ($('#display_sw3').is(":checked")) {
      client.publish(device_topic + 'actions/sw3', "1");
      imagen3.src = img2;
      imagen3.classList.remove("hc-icono-cancel");
      imagen3.classList.add("hc-icono-check");
    } else {
      client.publish(device_topic + 'actions/sw3', "0");
      imagen3.src = img1;
      imagen3.classList.remove("hc-icono-check");
      imagen3.classList.add("hc-icono-cancel");
    }
  }

  function slider_change() {
    value = $('#display_slider').val();
    client.publish(device_topic + 'actions/slider', value);
  }


  // FUNCIONES CIRCULOS DE ESTADOS

  function ce1_change() {
    if ($('#display_sw1').is(":checked")) {
      client.publish(device_topic + 'actions/sw1', "1"); //Valor que envio al broker
    } else {
      client.publish(device_topic + 'actions/sw1', "0");
    }
  }

  function ce2_change() {
    if ($('#display_sw1').is(":checked")) {
      client.publish(device_topic + 'actions/sw1', "1"); //Valor que envio al broker
    } else {
      client.publish(device_topic + 'actions/sw1', "0");
    }
  }

  function ce3_change() {
    if ($('#display_sw1').is(":checked")) {
      client.publish(device_topic + 'actions/sw1', "1"); //Valor que envio al broker
    } else {
      client.publish(device_topic + 'actions/sw1', "0");
    }
  }


  /*----------------*/
</script>