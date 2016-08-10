package com.hand.log;


import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

/**
 * Created by ljh on 2016/8/8.
 */
public class LogClass {
    private static Logger log = LoggerFactory.getLogger(LogClass.class);
    public static void main(String args[]) {
        log.debug("debug");
        log.info("info");
        log.warn("warn");
        log.error("error");
    }
}
