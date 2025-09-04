<!DOCTYPE html>
<html lang="es">

<head>
    <link rel="icon" type="image/png" href="<?php echo base_url('images/favicon.png') ?>">
    <meta charset="utf-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="description" content="A front-end template that helps you build fast, modern mobile web apps.">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <title>Sistema YAKU</title>

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
        
        <main class="">
            <div class="col-12">
                <a href="https://medtucats.fmgambino.info">
                    <img src="<?php echo base_url('/assets/img/logo_ministerio.png') ?>" class="logo1" />
                </a>
            </div>
            <div class="">
                <div class="">

                    <form class="" action="<?php echo base_url('register/doregister') ?>" method="post">


                        <div class=" box-registro ">
                            <div class="mb-4">
                                <span class="login-name" style="color: white">Registro de Usuario</span>
                            </div>
                            <div class="row">
                                <div class="col-12 col-md-6">
                                    <div class="" style="color: white;">
                                        <input class="mdl-textfield__input mt-4" placeholder="Usuario" type="text"
                                            id="name" name="name" value="<?php echo $name ?>">
                                    </div>
                                    <div class="">
                                        <input class="mdl-textfield__input mt-4" placeholder="Email" type="text"
                                            id="e-mail" name="email" value="<?php echo $email ?>">
                                    </div>
                                </div>
                                <div class="col-12 col-md-6">
                                    <div class="">
                                        <input class="mdl-textfield__input mt-4" placeholder="Contraseña"
                                            type="password" id="password" name="password">
                                    </div>
                                    <div class="">
                                        <input class="mdl-textfield__input mt-4" placeholder="Repetir Contraseña"
                                            type="password" id="password" name="retype">
                                    </div>
                                </div>
                            </div>
                            <div class="row form-inline mt-4">
                                <div class="col-4 ">
                                    <input type="checkbox" id="checkbox-1" class="mdl-checkbox__input" checked required>
                                </div>
                                <div class="col-8 pl-0">
                                    <a href="#" class=" terminos">
                                        <p style="color: white">Estoy de acuerdo con todas las declaraciones en los terminos y condiciones
                                            del servicio</p>
                                    </a>
                                </div>
                            </div>
                            <div class="d-flex mt-4">
                                <button type="submit" class="btn boton">
                                    REGISTRARSE
                                </button>
                            </div>
                        </div>
                        <div class="d-flex mt-4">
                            <a href="<?php echo base_url('login') ?>" class="yaestoyregistrado">
                                Ya estoy registrado. Iniciar Sesión
                            </a>
                        </div>
                    </form>
                    <div class="" style="color:green">
                        <?php echo $msg ?>
                    </div>
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
    <!-- endinject -->

</body>

</html>