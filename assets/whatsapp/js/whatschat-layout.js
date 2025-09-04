/*=================================================

Project: WhatsChat - WhatsApp Chat Widget jQuery Plugin
Author: Black Theme
Released On: 10, Aug 2019
@version: 1.0

===================================================*/

/* On Page Load Function */
$(document).ready(function(){

    // Disable Mouse Key Event
    document.onkeydown = function (e) 
    {
        //alert();
        return false;
    }

	/* Class Color Click Event Function */

	$(".color1" ).click(function(){
		$("#whatschat-color" ).attr("href", "css/colors/color-black.css");
		return false;
	});

	$(".color2" ).click(function(){
		$("#whatschat-color" ).attr("href", "css/colors/color-blue.css");
		return false;
	});

	$(".color3" ).click(function(){
		$("#whatschat-color" ).attr("href", "css/colors/color-green.css");
		return false;
	});

	$(".color4" ).click(function(){
		$("#whatschat-color" ).attr("href", "css/colors/color-orange.css");
		return false;
	});

	$(".color5" ).click(function(){
		$("#whatschat-color" ).attr("href", "css/colors/color-pink.css");
		return false;
	});
		
	$(".color6" ).click(function(){
		$("#whatschat-color" ).attr("href", "css/colors/color-purple.css");
		return false;
	});

	$(".color7" ).click(function(){
		$("#whatschat-color" ).attr("href", "css/colors/color-red.css");
		return false;
	});

	$(".color8" ).click(function(){
		$("#whatschat-color" ).attr("href", "css/colors/color-yellow.css");
		return false;
	});

	/* whatschat Slider Function */
	$('.icon').click (function(event){
		event.preventDefault();
		if( $ (this).hasClass('inOut')  ){
			$('.wc-setting').stop().animate({left:'-210px'},500 );
		} else{
			$('.wc-setting').stop().animate({left:'0px'},500 );
		} 
		$(this).toggleClass('inOut');
		return false;

	});

    // For the dropdown menu under the WhatsChat Style 10
    
    var countOption = $('.old-select option').size();
    
    function openSelect(){
        var heightSelect = $('.new-select').height();
        var j=1;
        $('.new-select .new-option').each(function(){
            $(this).addClass('reveal');
            $(this).css({
                'box-shadow':'0 1px 1px rgba(0,0,0,0.1)',
                'left':'0',
                'right':'0',
                'top': j*(heightSelect+1)+'px'
            });
            j++;
        });
    }
    
    function closeSelect(){
        var i=0;
        $('.new-select .new-option').each(function(){
            $(this).removeClass('reveal');
            if(i<countOption-3){
                $(this).css('top',0);
                $(this).css('box-shadow','none');
            }
            else if(i===countOption-3){
                $(this).css('top','3px');
            }
            else if(i===countOption-2){
                $(this).css({
                    'top':'7px',
                    'left':'2px',
                    'right':'2px'
                });
            }
            else if(i===countOption-1){
                $(this).css({
                    'top':'11px',
                    'left':'4px',
                    'right':'4px'
                });
            }
            i++;
        });
    }
    
    // Initialisation
    if($('.old-select option[selected]').size() === 1){
        $('.selection p span').html($('.old-select option[selected]').html());
    }
    else{
        $('.selection p span').html($('.old-select option:first-child').html());
    }
    
    $('.old-select option').each(function(){
        newValue = $(this).val();
        newHTML = $(this).html();
        $('.new-select').append('<div class="new-option" data-value="'+newValue+'"><p>'+newHTML+'</p></div>');
    });
    
    var reverseIndex = countOption;
    $('.new-select .new-option').each(function(){
        $(this).css('z-index',reverseIndex);
        reverseIndex = reverseIndex-1;        
    });
    
    closeSelect();

    // Ouverture / Fermeture
    $('.selection').click(function(){
        $(this).toggleClass('open');
        if($(this).hasClass('open')===true){openSelect();}
        else{closeSelect();}
    });
 
    $('.wc-button2').hide();
    $('.wc-button3').hide();
    $('.wc-button4').hide();
    $('.wc-button5').hide();
    $('.wc-button6').hide();
    $('.wc-button7').hide();
    // Selection 
    $('.new-option').click(function(){
        
        var newValue = $(this).data('value');

        $('.wc-button1').hide();
        $('.wc-button2').hide();
        $('.wc-button3').hide();
        $('.wc-button4').hide();
        $('.wc-button5').hide();
        $('.wc-button6').hide();
        $('.wc-button7').hide();

        if(newValue == 'wc-style1'){
        	$('.wc-button1').fadeIn();
        }
        else if(newValue == 'wc-style2'){
        	$('.wc-button2').fadeIn();
        }
        else if(newValue == 'wc-style3'){
        	$('.wc-button3').fadeIn();
        }
        else if(newValue == 'wc-style4'){
        	$('.wc-button4').fadeIn();
        }
        else if(newValue == 'wc-style5'){
        	$('.wc-button5').fadeIn();
        }
        else if(newValue == 'wc-style6'){
        	$('.wc-button6').fadeIn();
        }
        else if(newValue == 'wc-style7'){
        	$('.wc-button7').fadeIn();
        }

        // Selection New Select
        $('.selection p span').html($(this).find('p').html());
        $('.selection').click();
        
        // Selection Old Select
        $('.old-select option[selected]').removeAttr('selected');
        $('.old-select option[value="'+newValue+'"]').attr('selected','');            
    });
 
    $(".wc-zoom").hover(function(){
        
        $(this).addClass('transition');
    }, function(){
        
        $(this).removeClass('transition');
    });  
});
