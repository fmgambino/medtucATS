<header class="mdl-layout__header">
    <div>

    </div>
    <div class=" form-inline">
        <div class="d-none d-sm-none d-md-block">
            <img src="<?php echo base_url('image/favicon.png') ?>" class="logo2">
        </div>
        <div class="mdl-layout__header-row ml-auto">
            <select id="device_select" class="btn hc-select-device " onchange="change_device()" class="" name="">
                <option value="">Selecione Dispositivo</option>
                <?php foreach ($devices as $device) { ?>
                    <option value="<?php echo $device['device_id'] ?>" <?php if ($_SESSION['selected_device'] == $device['device_id']) {
                                                                            echo "selected";
                                                                        } ?>><?php echo $device['device_alias'] ?>
                    </option>
                <?php } ?>
            </select>

            <div class="avatar-dropdown " id="icon" style="padding-right: 0px;padding-left: 0px;">
                <a href="https://medtucats.fmgambino.info/app/profile">
                <span class=" hc-color-text-negro"><?php echo $_SESSION['user_name']; ?></span>
                <img style="padding-right: 0px;padding-left: 0px;" class="" src="<?php echo $_SESSION['user_image']; ?>">
            </div>

            <button id="more" class="mdl-button mdl-js-button mdl-button--icon">
                <i class="material-icons hc-text-negro">more_vert</i>
            </button>

            <ul class="mdl-menu mdl-menu--bottom-right mdl-js-menu mdl-js-ripple-effect mdl-shadow--2dp settings-dropdown" for="more">
                <a class="mdl-menu__item" href="https://medtucats.fmgambino.info/app/devices">
                    Configuración
                </a>
                <a class="mdl-menu__item" href="https://medtucats.fmgambino.info/soporte/">
                    Soporte
                </a>
                <a class="mdl-menu__item" href="https://medtucats.fmgambino.info/faq">
                    F.A.Q.
                </a>
                <a href="https://medtucats.fmgambino.info/app">
                    <li class="mdl-menu__item mdl-list__item">
                        <span class="mdl-list__item-primary-content">
                            <i class="material-icons mdl-list__item-icon text-color--secondary">exit_to_app</i>
                            Salir
                        </span>
                    </li>
                </a>
            </ul>
        </div>
    </div>
</header>

<script type="text/javascript">
    function change_device() {

        var device_id = $("#device_select").val();
        console.log(device_id);
        $.post("<?php echo base_url('devices/change_device'); ?>", {
            device_id: device_id
        }, function(result) {
            location.reload();
        });
    }
</script>