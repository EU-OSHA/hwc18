function ipad_fix_iframe_width() {
	if (jQuery(window).width() > jQuery(window).height()) {
        jQuery('.fb-post').addClass('ipad_fix_width');
	} else {
        jQuery('.fb-post').removeClass('ipad_fix_width');
	}
    setTimeout(ipad_fix_iframe_width, 5000);
}

window.onorientationchange = function() {
    ipad_fix_iframe_width();
}

jQuery(document).ready(function() {

    jQuery(".start-here .col-inner").click(function() {
        window.location = jQuery(this).find("a").attr("href");
        return false;
    });

    if ((jQuery('.fb-post').length) && (jQuery(window).width()<=1024)) {
        setTimeout(ipad_fix_iframe_width, 5000);
    }

    //menu toolkit
    jQuery("#block-hwc-toolkit-toolkit-left-menu .key-menu-container >.menu >.menu__item.expanded >span").click(function(){
    	if(jQuery(this).siblings("ul").is(":visible")){
    		jQuery(this).removeClass("up-arrow");
    		//jQuery(this).removeClass("active");
    		jQuery(this).siblings("ul").slideUp();
    	}else{
    		jQuery(this).addClass("up-arrow");
    		//jQuery(this).addClass("active");
    		jQuery(this).siblings("ul").slideDown();
    	}
    	
    });

    //menu toolkit tablet & mobile
    jQuery("#block-hwc-toolkit-toolkit-left-menu .key-menu-container >.menu-index").click(function(){
    	if(jQuery(this).siblings(".menu").is(":visible")){
    		jQuery(this).removeClass("up-arrow");
    		//jQuery(this).removeClass("active");
    		jQuery(this).siblings(".menu").slideUp();
    	}else{
    		jQuery(this).addClass("up-arrow");
    		//jQuery(this).addClass("active");
    		jQuery(this).siblings(".menu").slideDown();
    	}
    	
    });

    //toolkit download pdf & links
    jQuery(".node-type-tk-example .node-tk-example .group-left .field-name-field-download-pdf .field-label, .node-type-tk-example .node-tk-example .group-left .field-name-field-external-link .field-label").click(function(){
    	if(jQuery(this).siblings(".field-items").is(":visible")){
    		jQuery(this).removeClass("up-arrow");
    		//jQuery(this).removeClass("active");
    		jQuery(this).siblings(".field-items").slideUp();
    	}else{
    		jQuery(this).addClass("up-arrow");
    		//jQuery(this).addClass("active");
    		jQuery(this).siblings(".field-items").slideDown();
    	}
    });


    // Detect objectFit support
	//if('objectFit' in document.documentElement.style === false) {
	  
	  // assign HTMLCollection with parents of images with objectFit to variable
	  var container = document.getElementsByClassName('flickr-img-wrap');
	  
	  // Loop through HTMLCollection
	  for(var i = 0; i < container.length; i++) {
	    
	    // Asign image source to variable
	    var imageSource = container[i].querySelector('img').src;
	    
	    // Hide image
	    container[i].querySelector('img').style.display = 'none';
	    
	    // Add background-size: cover
	    container[i].style.backgroundSize = 'cover';
	    
	    // Add background-image: and put image source here
	    container[i].style.backgroundImage = 'url(' + imageSource + ')';
	    
	    // Add background-position: center center
	    container[i].style.backgroundPosition = 'center center';
	  }
	//}


	// Hide Header on on scroll down
	var didScroll;
	var lastScrollTop = 0;
	var delta = 5;
	var navbarHeight = jQuery('header').outerHeight()-70;

	jQuery(window).scroll(function(event){
	    didScroll = true;
	});

	setInterval(function() {
	    if (didScroll) {
	        hasScrolled();
	        didScroll = false;
	    }
	}, 110);

	function hasScrolled() {
	    var st = jQuery(this).scrollTop();
	    
	    // Make sure they scroll more than delta
	    if(Math.abs(lastScrollTop - st) <= delta)
	        return;
	    
	    // If they scrolled down and are past the navbar, add class .nav-up.
	    // This is necessary so you never see what is "behind" the navbar.
	    if (st > lastScrollTop && st > navbarHeight){
	        // Scroll Down
	        jQuery('header').removeClass('nav-down').addClass('nav-up');
	    } else {
	        // Scroll Up
	        if(st + jQuery(window).height() < jQuery(document).height()) {
	            jQuery('header').removeClass('nav-up').addClass('nav-down');
	        }
	    }
	    
	    lastScrollTop = st;
	}

	//fixing sticky menu
	var num = 150; //number of pixels before modifying styles
	if(jQuery("body").height()>=550){
		jQuery(window).bind('scroll', function () {
		    if (jQuery(window).scrollTop() > num) {
		        jQuery("#navbar").addClass("sticky-menu");
		    } else {
		        jQuery('#navbar').removeClass('sticky-menu');
		    }
		});
	};

	//removing the sticky only for this app form page
	/*if(jQuery("body").height()>=1250){
		jQuery(window).bind('scroll', function () {
			if (jQuery(window).scrollTop() > num) {
		        jQuery('.page-node-225 #navbar').removeClass('sticky-menu');
		    }
		});
	};*/

	/*Fix the target _blank when we import the content of CORPORATE*/

	jQuery('.node-news a[href^="https://osha.europa.eu"]').attr('target','_blank');
	jQuery('.node-press-release a[href^="https://osha.europa.eu"]').attr('target','_blank');
	jQuery('.node-events a[href^="https://osha.europa.eu"]').attr('target','_blank');

	/*Fix the target _blank OCP links*/

	jQuery('.node-type-partner .pane-node-field-website a').attr('target','_blank');
	jQuery('.node-type-partner .field-name-field-website a').attr('target','_blank');
	jQuery('.node-type-partner .profile-col-right-2 .field-type-link-field a').attr('target','_blank');
	jQuery('.node-type-partner .panels-flexible-column-last .field-type-link-field a').attr('target','_blank');


	/*Fix the height of the Everis iframe*/

	jQuery('#iframe-application').load(function() {
		var alto = jQuery('#iframe-application').contents().height();
		jQuery('#iframe-application').css("height",alto + 50);
	});


	var windowWidth= jQuery(window).width();//window size

	/*
	jQuery(window).resize(function() {
	    windowWidth= jQuery(window).width();//window size, when resizing
	    if(jQuery("#napo_films").length > 0){
	    	location.reload();
	    }
	});
	*/
	
	/*View newsletter captcha*/

	jQuery( "#edit-email-osh" ).click(function() {
  		jQuery('#block-osha-newsletter-osha-newsletter-subscribe div.captcha').show();
	});

	/*changing capcha on click*/
	jQuery("#edit-email").click(function(){
		jQuery("#edit-submit").css({'margin-left':'auto', 'margin-right':'auto', 'display':'block'});
		jQuery(this).css("margin-right", "22px");
		jQuery(".form-item-email").css({"margin-right":"auto", "margin-left":"auto", "display":"table"});
	});

	/*adding color to "sort by" labels when is checked*/
	jQuery(".pane-hwc-practical-tool-hwc-practical-tool-listing #edit-content .form-type-radios.form-item-sort input:checked").parent('label').css({'color':'#749b00','font-weight':'bold'});
	
	/*show more and less newsletters*/
	jQuery(".more_newsletters").click(function(){
		jQuery("div.newsletter-item:gt(3)").slideDown();
		jQuery(".more_newsletters").hide();
		
		if(windowWidth <= 992){
			jQuery(".less_newsletters").show().css("display", "block");
		}else{
			jQuery(".less_newsletters").show().css("display", "inline-block");
		}
	});
	jQuery(".less_newsletters").click(function(){
		jQuery("div.newsletter-item:gt(3)").slideUp();
		jQuery(".less_newsletters").hide();
		jQuery(".more_newsletters").show();
	});

	/*specific functions for tablet and/or mobile */
	funcionesTabletMovil();

	funcionesMovil();

	funcionesDesktop();
	
	
	//Fixing responsive menu to iPhone
	jQuery(document).ready(function() {
		jQuery(".dropdown-toggle").dropdown();
		//Hover for download episodes on iPad
		document.addEventListener("touchstart", function() {},false);
	});

	
	

	/*filters of list dropdown*/
	jQuery(".form-item-field-publication-type > label").click(function() {
				jQuery(this).toggleClass("active");
	});
	jQuery(".form-item-language > label").click(function() {
		jQuery(this).toggleClass("active");
	});
	jQuery(".form-item-field-priority-area > label").click(function() {
		jQuery(this).toggleClass("active");
	});
	jQuery(".form-item-relevant-for > label").click(function() {
		jQuery(this).toggleClass("active");
	});
	jQuery(".form-item-languages > label").click(function() {
		jQuery(this).toggleClass("active");
	});
	jQuery(".form-item-publication-type > label").click(function() {
		jQuery(this).toggleClass("active");
	});

	/*filters of list dropdown*/
	if(jQuery(".form-item-field-publication-type div").is(':visible')){
		jQuery(".form-item-field-publication-type > label").addClass("active");
	};
	if(jQuery(".form-item-language div").is(':visible')){
		jQuery(".form-item-language > label").addClass("active");
	};
	if(jQuery(".form-item-field-priority-area div").is(':visible')){
		jQuery(".form-item-field-priority-area > label").addClass("active");
	};
	if(jQuery(".form-item-relevant-for div").is(':visible')){
		jQuery(".form-item-relevant-for > label").addClass("active");
	};
	if(jQuery(".form-item-languages div").is(':visible')){
		jQuery(".form-item-languages > label").addClass("active");
	};
	if(jQuery(".form-item-publication-type div").is(':visible')){
		jQuery(".form-item-publication-type > label").addClass("active");
	};
	
	/*Private zone hover effect menu*/
	jQuery(".profile-edit-links-container .hwc-partner-private-link-block-title a").hover(function(){
		jQuery(".profile-edit-links-container .pane-content").css("background", "inherit");
		jQuery(this).parent().parent().css("background", "#e2e2e3");
	});
	jQuery(".profile-edit-links-container .hwc-partner-private-link-block-title a").mouseleave(function(){
		jQuery(".profile-edit-links-container .pane-content").css("background", "inherit");
		//jQuery(this).parent().parent().css("background", "#e2e2e3");
	});


	/**
	 * Clearable text inputs
	
	function tog(v){return v?'addClass':'removeClass';} 
	jQuery(document).on('input', '.clearable', function(){
	    jQuery(this)[tog(this.value)]('x');
	}).on('mousemove', '.x', function( e ){
	    jQuery(this)[tog(this.offsetWidth-18 < e.clientX-this.getBoundingClientRect().left)]('onX');
	}).on('touchstart click', '.onX', function( ev ){
	    ev.preventDefault();
	    jQuery(this).removeClass('x onX').val('').change();
	});
	 */
	 jQuery("#edit-search-block-form--2 ,#osha-publication-menu-publications-form input, #osha-publication-menu-case-studies-form input, #edit-search-api-views-fulltext-wrapper input").addClear();
	/************************** FUNCTIONS *******************************/

	function funcionesDesktop () {
		jQuery(window).resize(function() {
	    	windowWidth= jQuery(window).width();//window size, when resizing
		    if(windowWidth > 976){//<-----functions for desktop
				
		    	jQuery('#block-hwc-toolkit-toolkit-left-menu .key-menu-container > .menu').css("display", "block");

			}else{
				jQuery('#block-hwc-toolkit-toolkit-left-menu .key-menu-container > .menu').css("display", "none");
				jQuery('#block-hwc-toolkit-toolkit-left-menu .key-menu-container > .menu-index').removeClass("up-arrow");
			}//<-----End: functions for desktop
		});
		
	}
	function funcionesTabletMovil () {
		if(windowWidth <= 992){//<-----functions for tablet and/or mobile
			


		}//<-----End: functions for tablet and/or mobile
	}

	function funcionesMovil () {
		jQuery("#block-menu-menu-header-login, #block-lang-dropdown-language").addClass("visibility");
		if(windowWidth <= 767){//<-----functions for mobile

			//Menu function, transform the menu icon in a x

			jQuery(".navbar-toggle").on("click", function () {
		    	jQuery(this).toggleClass("active");
				jQuery("#block-menu-menu-header-login, #block-lang-dropdown-language").toggleClass("visibility");
			});
			
			//Additional Resources Block
			
			jQuery(".field-name-field-aditional-resources h4.pane-title").click(function() {
				jQuery(this).toggleClass("closeLabel");
				jQuery(this).next("div").toggle();
			});
			
			//Press Room
			
			jQuery(".pane-osha-press-release-osha-press-rel-become-partner h2.pane-title").click(function() {
				jQuery(this).toggleClass("closeLabel");
				jQuery(this).next("div").toggle();
			});
			
			jQuery(".pane-press-contacts h2.pane-title").click(function() {
				jQuery(this).toggleClass("closeLabel");
				jQuery(this).next("div").toggle();
			});
			
			jQuery(".pane-osha-press-release-osha-press-kit h2.pane-title").click(function() {
				jQuery(this).toggleClass("closeLabel");
				jQuery(this).next("div").toggle();
			});
			
		}
	}

	//AÑADIDO GALDER
	jQuery(".page-glossary-list .view-content .glossary_type .type-name").click(function(){
		jQuery(this).addClass("active");
		});
});
