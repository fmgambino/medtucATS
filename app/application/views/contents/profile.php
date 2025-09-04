<main class="mdl-layout__content">

    <div class="mdl-grid mdl-grid--no-spacing dashboard">

        <div class="col-12">

            <!-- TEMP -->
            <div class="col-12 hc-box-profile">
                <div class="mdl-card mdl-shadow--2dp">
                    <div class="mdl-card__title ">
                        <h5 class="mdl-card__title-text text-color--white">INFORMACIÓN DEL PERFIL</h5>
                    </div>
                    <div class="mdl-card__supporting-text">
                        <form enctype="multipart/form-data" class="" action="https://medtucats.fmgambino.info/app/profile/change" method="post">
                            <div class="mdl-grid">
                                <div class="mdl-textfield  full-size">
                                    <input class="mdl-textfield__input hc-color-text-gris hc-text-center " type="text" name="user_name" value="<?php echo $_SESSION['user_name']; ?>">
                                    <label class="hc-color-text-gris mb-4">Nombre del Usuario</label>
                                </div>
                                <div class="mdl-textfield mdl-js-textfield mdl-textfield--floating-label full-size">
                                    <input class="mdl-textfield__input hc-color-text-gris hc-text-center " type="text" name="email" value="<?php echo $_SESSION['user_email']; ?>">
                                    <label class="hc-color-text-gris mb-4">Correo Electrónico</label>
                                </div>
                                <div class="mdl-textfield mdl-js-textfield mdl-textfield--floating-label full-size">
                                    <input class="mdl-textfield__input hc-color-text-gris hc-text-center " type="password" name="password">
                                    <label class="hc-color-text-gris mb-4" for="password">Contraseña</label>
                                </div>
                                <div class="mdl-textfield mdl-js-textfield mdl-textfield--floating-label full-size">
                                    <input class="mdl-textfield__input hc-color-text-gris hc-text-center " type="file" name="image">
                                </div>
                                
                                <button <?php if ($_SESSION['user_id'] == 4) {
                                            echo "disabled";
                                        } ?> class="btn boton " data-upgraded=",MaterialButton,MaterialRipple" type="submit">
                                    Guardar                                    
                                </button>
                            </div>
                    </div>
                    </form>
                </div>
            </div>
        </div>
        <!-- Table-->

    </div>

</main>