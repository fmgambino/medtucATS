<!DOCTYPE html>
<html lang="en">

<head>
    <link rel="icon" type="image/png" href="/assets/icons/faviconMedTuc.ico">
    <meta charset="utf-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="description" content="A front-end template that helps you build fast, modern mobile web apps.">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <title>SICYM ATS - Ministerio de Educación - Gobierno de Tucumán</title>

    <!-- Add to homescreen for Chrome on Android -->
    <meta name="mobile-web-app-capable" content="yes">


    <!-- Add to homescreen for Safari on iOS -->
    <meta name="apple-mobile-web-app-capable" content="yes">
    <meta name="apple-mobile-web-app-status-bar-style" content="black">
    <meta name="apple-mobile-web-app-title" content="Material Design Lite">


    <!-- Tile icon for Win8 (144x144 + tile color) -->
    <meta name="msapplication-TileImage"
        content="<?php echo base_url('images/touch/ms-touch-icon-144x144-precomposed.png') ?>">
    <meta name="msapplication-TileColor" content="#3372DF">

    <!-- SEO: If your mobile URL is different from the desktop URL, add a canonical link to the desktop page https://developers.google.com/webmasters/smartphone-sites/feature-phones -->
    <!--
  <link rel="canonical" href="http://www.example.com/">
-->

    <link href='https://fonts.googleapis.com/css?family=Roboto:400,500,300,100,700,900' rel='stylesheet'
        type='text/css'>
    <link href="https://fonts.googleapis.com/icon?family=Material+Icons" rel="stylesheet')?>">
    <!-- inject:css -->
    <link rel="stylesheet" href="<?php echo base_url('css/lib/getmdl-select.min.css') ?>">
    <link rel="stylesheet" href="<?php echo base_url('css/lib/nv.d3.min.css') ?>">
    <link rel="stylesheet" href="<?php echo base_url('css/application.min.css') ?>">

    <link rel="stylesheet" href="<?php echo base_url('css/bootstrap.css') ?>">
    <link rel="stylesheet" href="<?php echo base_url('css/hydrocrop.css') ?>">
    <!-- endinject -->


</head>

<body class="color-fondo">

    <div class="">


        <main class="video">

        <section class="imgBackground"></section>

        <!-- <section class="imgBackground"></section> -->
         
            <div class="col-12">
                <a href="https://medtucats.fmgambino.info">
                    <img src="https://medtucats.fmgambino.info/assets/img/logo_ministerio.png" class="logo1" />
                </a>
            </div>
            <div class=" col-12 aling-center">
                <div class=" hc-box-login border p-4">
                    <div class="  ">
                        <form class="" action="<?php echo base_url('login/dologin') ?>" method="post">
                            <div class="col-12  mt-4">
                                <span class="" style="color: white;">Inicie sesión con su cuenta IoT</span>
                            </div>
                            <div class="col-12  mt-4">
                                <div class="mb-3">
                                    <input class=" hc-form-control inputs" placeholder="Correo Electrónico" type="text"
                                        name="email" value="demo@demo.com" id="e-mail">
                                    <label class="" for="e-mail"></label>
                                </div>
                                <div class="">
                                    <input class=" hc-form-control inputs" placeholder="Contraseña" type="password"
                                        id="password" name="password" value="demo0381">
                                    <label class="" for="password"></label>
                                </div>
                            </div>
                            <div class=" ">
                                <div class="d-flex">
                                    <a href="<?php echo base_url('register') ?>" class="">No eres Cliente?</a>
                                </div>
                                <br>
                                <div class="loginboton">
                                    <button type="submit" class="btn boton col-12">
                                        INGRESAR
                                    </button>
                                </div>
                            </div>
                        </form>
                    </div>
                </div>
                <div class="mt-5">
                <div class="text-center tamaño">Sistema Integral de Control y Monitoreo ATS</div>
                <div class="text-center tamaño mt-1">2023 - Ministerio de Educación - Subdirección de Informática.</div>
                </div>
                <div class="" style="color:red">
                    <?php echo $msg ?>
                </div>
            </div>
        </main>
    </div>

    <!-- inject:js -->
    <script src="<?php echo base_url('js/d3.min.js') ?>"></script>
    <script src="<?php echo base_url('js/getmdl-select.min.js') ?>"></script>
    <script src="<?php echo base_url('js/material.min.js') ?>"></script>
    <script src="<?php echo base_url('js/nv.d3.min.js') ?>"></script>
    <script src="<?php echo base_url('js/layout/layout.min.js') ?>"></script>
    <script src="<?php echo base_url('js/scroll/scroll.min.js') ?>"></script>
    <script src="<?php echo base_url('js/widgets/charts/discreteBarChart.min.js') ?>"></script>
    <script src="<?php echo base_url('js/widgets/charts/linePlusBarChart.min.js') ?>"></script>
    <script src="<?php echo base_url('js/widgets/charts/stackedBarChart.min.js') ?>"></script>
    <script src="<?php echo base_url('js/widgets/employer-form/employer-form.min.js') ?>"></script>
    <script src="<?php echo base_url('js/widgets/line-chart/line-charts-nvd3.min.js') ?>"></script>
    <script src="<?php echo base_url('js/widgets/map/maps.min.js') ?>"></script>
    <script src="<?php echo base_url('js/widgets/pie-chart/pie-charts-nvd3.min.js') ?>"></script>
    <script src="<?php echo base_url('js/widgets/table/table.min.js') ?>"></script>
    <script src="<?php echo base_url('js/widgets/todo/todo.min.js') ?>"></script>
    <script src="<?php echo base_url('js/bootstrap.js') ?>"></script>
    <!-- endinject -->

</body>

</html>