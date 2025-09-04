<main class=" container-fluid" style="overflow-y:scroll;">

    <div class="">

        <div class="row">
            <!-- columna1  -->
            <div class="col-12 col-lg-4">
                <div class=" form-inline">
                    <div class="col-6" style="padding-left: 0px; padding-right: 7px;">
                        <div class="mdl-card--expand color-azul-1 text-center pb-3" style="height: 109px;">
                            <h4 class=" hc-color-text-blanco ">Extractor</h4>
                            <div class=" form-inline d-flex " style="justify-content: center;">
                                <!-- SWITCH-->
                                <label class="switch mr-2" style="margin-bottom: 0px;">
                                    <input onchange="sw1_change()" type="checkbox" id="display_sw1">
                                    <span class="slider round"></span>
                                </label>
                                <img src="<?php echo base_url('images/cancel.png') ?>" class="hc-icono-cancel ml-2"
                                    id="icono1" alt="">
                            </div>
                        </div>
                    </div>
                    <div class="col-6" style="padding-right: 0px; padding-left: 7px;">
                        <div class="mdl-card--expand color-azul-1 text-center pb-3" style="height: 109px;">
                            <h4 class=" hc-color-text-blanco  ">Nivel Bateria</h4>
                            <div class="form-inline" style="display: inline-flex">
                                <div class="progress "
                                    style=" width: 80px;height: 30px; border: 2px solid white;position: relative;">
                                    <div id="bateria" class="progress-bar progress-bar-striped progress-bar-animated "
                                        role="progressbar"
                                        style="width: 90% ; background-color: #2cff00 !important; flex-direction: row !important;"
                                        aria-valuenow="45" aria-valuemin="0" aria-valuemax="100">
                                    </div>
                                    <div class="form-inline ml-4" style="position: absolute;">
                                        <h4 id="valorBateria" style="">30</h4>
                                        <h5>%</h5>
                                    </div>

                                </div>
                                <div class="progress"
                                    style="   width: 10px;height: 20px; border-radius: 0; border: 2px solid white;">
                                    <div class="progress-bar" role="progressbar" style="width: 0% " aria-valuenow="0"
                                        aria-valuemin="0" aria-valuemax="100"></div>
                                </div>
                            </div>

                        </div>
                    </div>
                </div>
                <div class=" ">
                    <div class=" mdl-card--expand color-azul-1 ">
                        <div class="form-inline">
                            <div class="col-4 col-md-6 hc-color-text-blanco ">
                                <div class="col-12 form-inline " style="justify-content: center;">
                                    <h4 class=" mb-0 ">Volumen</h4>
                                    <img src="<?php echo base_url('images/iconoWater.svg') ?>" class="icono">
                                </div>
                                <div class="col-12 form-inline mt-3" style="justify-content: center;">
                                    <p id="valorVolumen" class="weather-temperature mr-1">--</p>
                                    <h4 class="hc-unidades">Lts</h4>
                                </div>
                            </div>
                            <div class="col-8 col-md-6" style="width: 80%; height: 130px;">
                                <div id="gaugeVolumen"></div>
                            </div>
                        </div>
                    </div>
                </div>
            </div>
            <!--columna 2-->
            <div class="col-12 col-lg-4 ">

                <div class=" ">

                    <div class=" mdl-card--expand color-azul-1 ">
                        <div class="form-inline">
                            <div class=" col-4 col-md-6 hc-color-text-blanco ">
                                <div class="col-12 form-inline text-center ">
                                    <h4 class=" mb-0 ">Temperatura</h4>
                                    <img src="<?php echo base_url('images/iconoTemp.svg') ?>" class="icono">
                                </div>
                                <div class="col-12 form-inline mt-3">
                                    <p id="valorTemperatura" class="weather-temperature mr-1">--</p>
                                    <h4 class="hc-unidades">°C</h4>
                                </div>
                            </div>
                            <div class="col-8 col-md-6 " style="width: 100%; height: 80px;">
                                <div id="gaugeTemperatura"></div>
                            </div>
                        </div>
                    </div>
                </div>


                <div class=" ">
                    <div class=" mdl-card--expand color-azul-1 ">
                        <div class="form-inline">
                            <div class="col-4 col-md-6 hc-color-text-blanco ">
                                <div class="col-12 form-inline text-center" style="justify-content: center;">
                                    <h4 class=" mb-0 ">Humedad</h4>
                                    <img src="<?php echo base_url('images/iconoWater.svg') ?>" class="icono">
                                </div>
                                <div class="col-12 form-inline mt-3" style="justify-content: center;">
                                    <p id="valorHumedad" class="weather-temperature mr-1">--</p>
                                    <h4 class="hc-unidades">%</h4>
                                </div>
                            </div>
                            <div class="col-8 col-md-6 " style="width: 100%; height: 130px;">
                                <div id="gaugeHumedad"></div>
                            </div>
                        </div>
                    </div>
                </div>
            </div>
            <!--columna 3-->
            <div class="col-12 col-lg-4 ">
                <div class=" ">

                    <div class=" mdl-card--expand color-azul-1 ">
                        <div class="form-inline">
                            <div class=" col-4 col-md-6 hc-color-text-blanco ">
                                <div class="col-12 form-inline " style="justify-content: center;">
                                    <h4 class=" mb-0 ">Viento</h4>
                                    <img src="<?php echo base_url('images/iconoViento.svg') ?>" class="icono">
                                </div>
                                <div class="col-12 form-inline mt-3 " style="justify-content: center;">
                                    <p id="valorViento" class="weather-temperature mr-1 ">23.11</p>
                                    <h4 class="hc-unidades">km/h</h4>
                                </div>
                            </div>

                            <div class="col-8 col-md-6 " style="width: 100%; height: 80px;">
                                <div id="gaugeViento"></div>
                            </div>
                        </div>
                    </div>

                </div>
                <div class=" ">
                    <div class=" mdl-card--expand color-azul-1 ">
                        <div class="form-inline">
                            <div class="col-4 col-md-6 hc-color-text-blanco ">
                                <div class="col-12 form-inline " style="justify-content: center;">
                                    <h4 class=" mb-0 ">Ph H2O</h4>
                                    <img src="<?php echo base_url('images/iconoWater.svg') ?>" class="icono">
                                </div>
                                <div class="col-12 form-inline mt-3" style="justify-content: center;">
                                    <p id="valorPh" class="weather-temperature mr-1">--</p>

                                </div>
                            </div>
                            <div class="col-8 col-md-6 " style="width: 100%; height: 130px;">
                                <div id="gaugePh"></div>
                            </div>
                        </div>
                    </div>
                </div>
            </div>


        </div>
        <!--Graficos-->
        <div class=" form-inline ">
            <div class="col-12 col-md-6 pl-0 padding-r-0">
                <div id="grafico1" class="color-azul-1 pl-3 graficos" style=" ">
                </div>
            </div>
            <div class="col-12 col-md-6 pr-0 padding-l-0">
                <div id="grafico2" class="color-azul-1 pl-3 graficos" style=" "></div>
            </div>
        </div>
        <div class="col-12 col-md-4 hc-box-a">
            <div class="mdl-card  trending">
                <div>
                    <span class="mdl-list__item-secondary-content" style="padding-top: 6px;">
                    </span>
                </div>
            </div>
        </div>
        <!-- Actuadores-->
        <div class="row">

        </div>
    </div>
    </div>
</main>

<!-- <script src="<?php echo base_url('js/progresbarlmz.js') ?>"></script> -->
<!-- <script src="<?php echo base_url('js/graficos.js') ?>"></script> -->

<script>
    console.log("llegue aqui en main.php");
    const options = {
        connectTimeout: 1000,
        // Authentication
        clientId: 'esp32_fmg_' + Math.floor((Math.random() * 1000000) + 1),
        username: '<?php echo MQTT_USER; ?>',
        password: '<?php echo MQTT_PASSWORD; ?>',
        keepalive: 60,
        clean: true,
    }

    console.log("options = ", options);

    // WebSocket connect url
    const WebSocket_URL = 'wss://broker.emqx.io:8084/mqtt';
    const client = mqtt.connect(WebSocket_URL, options)

    var device_topic = '<?php echo ROOT_TOPIC . "/" . $_SESSION['selected_topic'] . "/" ?>';
    client.on('connect', () => {
        console.log('Conexión Exitosa ^_^');

        client.subscribe(device_topic + "data", {
            qos: 0
        }, (error) => {
            if (error) {
                console.log("Error al Suscribir");
            } else {
                console.log("Suscrito al Broker con Exito!");
                console.log("Proyecto de Inversión");
                console.log("San Miguel de Tucumán - Tucumán - Argentina");
                console.log("2024-04");
            }

        })
    })




    console.log("url : ", '<?php echo base_url() ?>')

    var contCo2 = 0;
    var contcdtv = 0;
    var sumadorA = 0;
    var sumadorB = 0;
    var sumadorC = 0;
    var co2, cdtv;
    //----variables globales---------------------------------------------------------

    var GlobalTemp = 0;
    var GlobalViento = 1;
    var GlobalHumedad = 0;
    var GlobalPh = 0.0 ;
    var GlobalVolumen = 1.0;
    var GlobalNivelBateria = 10.0;
    // arrays para graficos------------------------------- 
    var GlobalFechas = [];
    var GlobalData2 = [];
    var GlobalData3 = [];
    //--------------------------------------------------------------------------------
    var delay = 500; 
    // aqui obtengo los datos directamente desde la base de datos

    const obtenerDatos = setInterval(() => {
        
    var deviceData = <?php echo json_encode($device_data); ?>;
    var ultimaFila = deviceData.length - 1;
    // Mostrar los datos en la consola
    //console.log("Datos de device_data:", deviceData);
    //conecto datos desde la db a las variables globales en main.php
    
    GlobalTemp = deviceData[ultimaFila].data_2;    
    GlobalHumedad = deviceData[ultimaFila].data_3; 
    GlobalPh = deviceData[ultimaFila].data_4;
    GlobalViento = deviceData[ultimaFila].data_5;
    GlobalVolumen = deviceData[ultimaFila].data_6;
    GlobalNivelBateria = deviceData[ultimaFila].data_7; 
     
    console.log("array de datos "); 
 

// // Iterar sobre los datos y extraer las fechas, data_2 y data_3
    GlobalFechas.splice(0, GlobalFechas.length);
    GlobalData2.splice(0, GlobalData2.length);
    GlobalData3.splice(0, GlobalData3.length);

 for (let index = 0; index < deviceData.length; index++) {
    GlobalFechas.push(deviceData[index].data_date);
    GlobalData2.push(deviceData[index].data_2);
    GlobalData3.push(deviceData[index].data_3);
 }

 pintarGauges();
    }, delay );

    //--------------------------------------------------------------------------------
    let receivedData = false;
    console.log('ejecuto client.on');
    client.on('message', (topic, message) => {
        console.log('se estan esperando los datos ....');
        console.log('Mensaje recibido en el tema:', topic);
        console.log('Contenido del mensaje:', message.toString().split(","));
        // Aquí puedes agregar tu lógica para procesar el mensaje
        console.log('Msg desde el topico: ', topic, ' ----> ', message.toString());

        receivedData = true; // Establecer la bandera a true cuando se recibe algún dato
    });

    // Establecer un temporizador para verificar si no se reciben datos después de cierto tiempo
    const timeout = setTimeout(() => {
        if (!receivedData) {
            console.log('No se recibieron datos dentro del período de tiempo especificado.');
            // Agregar aquí la acción que deseas realizar si no se reciben datos
        }
    }, 60000); // 5000 milisegundos (5 segundos) - ajusta el tiempo según tus necesidades


    //-------------------------------------------------------------------------
    // esta funcion muestra datos cuando se esta recibiendo datos desde el broquer mqtt .
    // client.on('message', (topic, message) => {
    //     console.log('Msg desde el topico: ', topic, ' ----> ', message.toString());

    //     if (topic == device_topic + "data") {
    //         var splitted = message.toString().split(",");

    //         console.log("splitted = ", splitted);

    //         // var melasa = splitted[0];
    //         // var temp = splitted[1];
    //         // var optico = splitted[2];
    //         // var sw1 = splitted[3];
    //         // var switch1 = splitted[4];

    //         // var switch4 = splitted[5];
    //         // var switch2 = splitted[6];
    //         // var switch3 = splitted[7];
    //         // var cdtv = splitted[8];

    //         // $("#display_melasa").html(melasa);
    //         // $("#display_tempamb").html(temp);

    //         // if (optico > 1000) {
    //         //     mensajeOptico = 'Bajo';
    //         // }
    //         // else {
    //         //     mensajeOptico = 'Alto';
    //         // }

    //         // $("#display_optico").html(mensajeOptico);

    //         // gTemp = temp;
    //         // gNivel = melasa;
    //         // gEspuma = optico;

    //         // if (switch1 == "1") {
    //         //     $("#display_sw1").prop('checked', true);
    //         // } else {
    //         //     $("#display_sw1").prop('checked', "");
    //         // }



    //     }


    // })

    //---------------------------------------------------------------------------------
    client.on('reconnect', (error) => {
        console.log('reconectando :', error);
    })

    client.on('error', (error) => {
        console.log('Connect Error:', error);
    })




    // FUNCIONES CIRCULOS DE ESTADOS

    // function ce1_change() {
    //     if ($('#display_sw1').is(":checked")) {
    //         client.publish(device_topic + 'actions/sw1', "1"); //Valor que envio al broker
    //     } else {
    //         client.publish(device_topic + 'actions/sw1', "0");
    //     }
    // }
console.log("fin script en main.php");
</script>

<script src="<?php echo base_url('js/graficos.js') ?>"></script>

<script>
    $(document).ready(function () {
        // Obtener el mensaje de las variables de sesión
        var mensaje = "<?php echo $this->session->userdata('msg_body'); ?>";

        // Verificar si hay un mensaje y mostrarlo en la consola
        if (mensaje !== "") {
            console.log("Mensaje: " + mensaje);
        }
    });
</script>