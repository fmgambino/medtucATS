<header class="mdl-layout__header">
    <div>

    </div>
    <div class=" form-inline">
        <div class="d-none d-sm-none d-md-block">
        <a href="https://medtucats.fmgambino.info"><img src="<?php echo base_url('/assets/img/logo_ministerio.png') ?>" class="logo2"></a>
        </div>
        <div class="ml-5" >
            <!--  -->
            <div id="ww_560ab0fe1545b" v='1.3' loc='auto' style="margin-left: 20px !important"
                a='{"t":"horizontal","lang":"es","sl_lpl":1,"ids":[],"font":"Arial","sl_ics":"one_a","sl_sot":"celsius","cl_bkg":"#FFFFFF00","cl_font":"rgba(255,255,255,1)","cl_cloud":"#d4d4d4","cl_persp":"#2196F3","cl_sun":"#FFC107","cl_moon":"#FFC107","cl_thund":"#FF5722","el_whr":3,"el_phw":3,"el_nme":3}'>
                <a href="https://weatherwidget.org/android-app/" id="ww_560ab0fe1545b_u"
                    target="_blank">weatherwidget.org/android-app</a>
            </div>
            <script async src="https://app1.weatherwidget.org/js/?id=ww_560ab0fe1545b"></script>
            <!--  -->
        </div>
        <div class="mdl-layout__header-row ml-auto">
            <select id="device_select" class="btn hc-select-device text-center" onchange="change_device()" class=""
                name="">
                <option value="">Selecione Dispositivo</option>
                <?php foreach ($devices as $device) { ?>
                <option value="<?php echo $device['device_id'] ?>" <?php if ($_SESSION['selected_device'] == $device['device_id']) {
                                                                            echo "selected";
                                                                        } ?>><?php echo $device['device_alias'] ?>
                </option>
                <?php } ?>
            </select>

            <div class="avatar-dropdown " id="icon" style="padding-right: 0px;padding-left: 0px;">
             <span class=" hc-color-text-negro pr-0"><?php echo $_SESSION['user_name']; ?></span>
             <img style="padding-right: 0px;padding-left: 0px;" class=""
                    src="<?php echo $_SESSION['user_image']; ?>">
            </div>

            <button id="more" class="mdl-button mdl-js-button mdl-button--icon">
                <i class="material-icons hc-text-negro">more_vert</i>
            </button>

            <ul class="mdl-menu mdl-menu--bottom-right mdl-js-menu mdl-js-ripple-effect mdl-shadow--2dp settings-dropdown"
                for="more">
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
var widgetSrc =
    "https://widgets.booked.net/weather/info?action=get_weather_info;ver=7;cityID=37228;type=6;scode=124;ltid=3457;domid=582;anc_id=60187;countday=4;cmetric=1;wlangID=4;color=ffffff;wwidth=250;header_color=ffffff;text_color=ffffff;link_color=ffffff;border_form=1;footer_color=ffffff;footer_text_color=ffffff;transparent=1;v=0.0.1";
widgetSrc += ';ref=' + widgetUrl;
widgetSrc += ';rand_id=99676';
var weatherBookedScript = document.createElement("script");
weatherBookedScript.setAttribute("type", "text/javascript");
weatherBookedScript.src = widgetSrc;
document.body.appendChild(weatherBookedScript)
</script>